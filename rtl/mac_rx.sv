module mac_rx #(
	parameter int POLY = 32'h04C11DB7,
	parameter int INIT = 32'hFFFFFFFF,
	parameter int FINAL_XOR = 32'hFFFFFFFF
)
(
	input logic clk,
	input logic rst_n,
	input logic [3:0] rx_dt,
	input logic rx_dt_valid,
	input logic rx_er,

	output logic [7:0] rx_byte,
	output logic valid,
	output logic start_of_frame,
	output logic end_of_frame,
	output logic crc
);

	logic [31:0] crc_reg;
	logic [31:0] crc_next;
	logic [7:0] full_nibble;
	logic feedback;
	logic nibble;
	logic [3:0] nibble_counter;
	
	typedef enum logic [1:0]{
		IDLE,
		SEARCH,
		RECIEVIED
	}sfd_states_t;

	sfd_states_t state, next_state;

	always_ff @(posedge clk or negedge rst_n) begin
		if(!rst_n) begin 
			valid <= 0;
			start_of_frame <= 0;
			end_of_frame <= 0;
			crc <= 0;
			crc_reg <= INIT;
			nibble <= 0;
			nibble_counter <= 0;
			state <= IDLE;
		end else if(rx_dt_valid && !rx_er) begin	
			crc_reg <= crc_next;
			state <= next_state;

			if(start_of_frame) begin
				valid <= 1;
			end else if(end_of_frame) begin 
				valid <= 0;
			end
			
			if(valid) begin
				if(nibble) begin
					full_nibble <= {rx_dt, full_nibble[3:0]};
				end else begin
					full_nibble <= {4'd0, rx_dt};	
				end
				nibble <= nibble + 1;
			end

			if(nibble_counter < 15 && (rx_dt == 4'h5 || rx_dt == 4'hD) && state = SEARCH) begin
				nibble_counter <= nibble_counter + 1;
			end else begin 
				nibble_counter <= 0;
			end
		end
	end

	always_comb begin 
		crc_next = crc_reg;
		for(int i = 0; i < 8; i++) begin
			feedback = crc_next[31] ^ rx_byte[7-i];
			crc_next = crc_next << 1;
			if(feedback) begin
				crc_next = crc_next ^ POLY;
			end
		end
		
		next_state = state;
		case(state) 
			IDLE : begin
				if(rx_dt_valid && !rx_er) begin 
					next_state = SEARCH;
				end
			end
		endcase	
	end

endmodule
