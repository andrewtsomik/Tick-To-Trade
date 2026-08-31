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
	logic first_byte_pending;
	logic [3:0] nibble_hold;
	
	typedef enum logic [1:0]{
		IDLE,
		SEARCH,
		RECEIVED
	}sfd_states_t;

	sfd_states_t state, next_state;

	always_ff @(posedge clk or negedge rst_n) begin
		if(!rst_n) begin 
			valid <= 0;
			crc <= 0;
			crc_reg <= INIT;
			nibble <= 0;
			nibble_counter <= 0;
			state <= IDLE;
			start_of_frame <= 0;
			first_byte_pending <= 0;
		end else if(rx_dt_valid && !rx_er) begin	
			crc_reg <= crc_next;
			state <= next_state;
			
			if(state == SEARCH && next_state == RECEIVED) begin
				nibble <= 0;
				first_byte_pending <= 1;
				valid <= 0;
			end else if(state == RECEIVED) begin
				if(nibble) begin
					valid <= 1;
					full_nibble <= {rx_dt, nibble_hold};
					first_byte_pending <= 0;
					start_of_frame <= first_byte_pending;
				end else begin
					valid <= 0;
					nibble_hold <= rx_dt;
					start_of_frame <= 0;
				end
				nibble <= nibble + 1;
			end

			if(nibble_counter < 15 && (rx_dt == 4'h5 || rx_dt == 4'hD) && state == SEARCH) begin
				nibble_counter <= nibble_counter + 1;
			end else begin 
				nibble_counter <= 0;
			end
		end else begin 
			state <= next_state;
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
		end_of_frame = 0;
		case(state) 
			IDLE : begin
				if(rx_dt_valid && !rx_er && nibble_counter < 15) begin 
					next_state = SEARCH;
				end else begin 
					next_state = IDLE;
				end
			end
			SEARCH : begin 
				if(rx_dt_valid && !rx_er && nibble_counter < 15) begin 
					if(rx_dt == 4'h5) begin 
						next_state = SEARCH;
					end else if(rx_dt == 4'hD) begin	
						next_state = RECEIVED;
					end else begin 
						next_state = IDLE;
					end
				end else begin 
					next_state = IDLE;
				end
			end
			RECEIVED : begin 
				if(rx_dt_valid && !rx_er) begin 
					if(rx_dt == 4'h5 && nibble_counter == 15) begin 
						next_state = RECEIVED;	
					end else begin 
						next_state = RECEIVED;
					end 
				end else begin 
					end_of_frame = 1;
					next_state = IDLE;
				end
			end
		endcase	
	end

	 
	assign rx_byte = full_nibble;
endmodule
