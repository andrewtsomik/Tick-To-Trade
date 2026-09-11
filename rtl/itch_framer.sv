module itch_framer#(
	parameter int MOLD_MESSAGE_COUNT_OFFSET = 18,
       	parameter int MOLD_MESSAGE_COUNT_LEN = 2,

	parameter int MESSAGE_LENGTH_OFFSET = 20,
	parameter int MESSAGE_LENGTH_LEN = 2,

	parameter int DATA_WIDTH = 8	
)
(
	input logic clk,
	input logic rst_n,
	input logic itch_valid,
	input logic [DATA_WIDTH-1:0] itch_byte,
	input logic start_of_boundary,
	input logic end_of_boundary,

	output logic [DATA_WIDTH-1:0] message_byte,
	output logic valid,
	output logic start_of_msg,
	output logic end_of_msg
);

	logic [4:0] itch_idx;
	logic [15:0] message_count;
	logic [15:0] message_length;
	logic [15:0] bytes_remaining;
	logic [15:0] messages_remaining;
	logic length_idx;

	typedef enum logic [2:0]{
		IDLE,
		READ_MOLD,
		READ_LENGTH,
		STREAMING,
		DONE
	}states_t;

	states_t state, next_state;

	always_ff @(posedge clk or negedge rst_n) begin 
		if(!rst_n || end_of_boundary) begin 
			itch_idx <= 0;
			message_length <= 0;
		end else if(itch_valid) begin 
			itch_idx <= itch_idx + 1;
			
			if(next_state == READ_LENGTH && !length_idx) begin 
				message_length <= {8'd0, itch_byte};
				length_idx <= 1;
			end else if(next_state == READ_LENGTH && length_idx) begin 
				message_length <= {message_length[7:0], itch_byte};
				length_idx <= 0;
			end
		end
	end

	always_ff @(posedge clk or negedge rst_n) begin 
		if(!rst_n) begin 
			state <= IDLE;
		end else begin 
			state <= next_state;
		end
	end
	
	always_ff @(posedge clk or negedge rst_n) begin 
		if(!rst_n || end_of_boundary) begin 
			message_count <= 0;
		end else if(itch_valid) begin 
			if(itch_idx == 18 && next_state == READ_MOLD) begin 
				message_count <= {8'd0, itch_byte};
			end else if(itch_idx == 19 && state == READ_MOLD) begin 
				message_count <= {message_count[7:0], itch_byte};
			end
		end
	end

	always_ff @(posedge clk or negedge rst_n) begin 
		if(!rst_n || end_of_boundary) begin 
			bytes_remaining <= 0;
			messages_remaining <= 0;
		end else if(itch_valid) begin 
			if(next_state == READ_MOLD && itch_idx == 19) begin 
				messages_remaining <= {message_count[7:0], itch_byte};
			end else if(next_state == STREAMING && bytes_remaining == 1) begin 
				messages_remaining <= messages_remaining - 1;
			end

			if(next_state == READ_LENGTH && length_idx) begin 
				bytes_remaining <= {message_length[7:0], itch_byte};
			end else if(next_state == STREAMING) begin 
				bytes_remaining <= bytes_remaining - 1;
			end
		end
	end

	always_comb begin 
		next_state = state;
		if(end_of_boundary) begin
			next_state = IDLE;
		end else begin
			case(state) 
				IDLE : begin
					if(start_of_boundary) begin 
						next_state = READ_MOLD;
					end	
				end

				READ_MOLD : begin 
					if(itch_valid && itch_idx == 19) begin 
						if(message_count == 0 || message_count == 16'hFFFF) begin 
							next_state = DONE;
						end else begin 
							next_state = READ_LENGTH;
						end
					end
				end

				READ_LENGTH : begin 
					if(itch_valid && length_idx) begin 
						next_state = STREAMING;
					end
				end
				
				STREAMING : begin 
					if(itch_valid && bytes_remaining == 1) begin 
						if(message_remaining > 1) begin 
							next_state = READ_LENGTH;
						end else begin 
							next_state = DONE;
						end
					end
				end

				DONE : begin 
					if(end_of_boundary) begin 
						next_state = IDLE;
					end
				end

				default : next_state = IDLE;
			endcase	
		end
	end
	
	
	assign valid = itch_valid && state == STREAMING;
	assign start_of_msg = itch_valid && state == STREAMING && message_length == bytes_remaining;
	assign end_of_msg = itch_valid && next_state == READ_LENGTH && state == STREAMING;
	assign message_byte = itch_byte;

endmodule
