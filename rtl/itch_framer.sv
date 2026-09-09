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

	typedef enum logic [2:0]{
		IDLE,
		READ_MOLD,
		READ_LENGTH,
		STREAMING,
		DONE
	}states_t;

	states_t state, next_state;

	always_ff @(posedge clk or negedge rst_n) begin 
		if(!rst_n || end_of_boundary || !bytes_remaining) begin 
			itch_idx <= 0;
		end else if(itch_valid) begin 
			itch_idx <= itch_idx + 1;
		end
	end

	always_ff @(posedge clk or negedge rst_n) begin 
		if(!rst_n) begin 
			state <= IDLE;
		end else begin 
			state <= next_state;
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
					if(itch_valid && 
				end
			endcase	
		end
	end

endmodule
