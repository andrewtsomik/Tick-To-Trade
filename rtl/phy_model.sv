//This is only a simulation PHY as the FPGA I use doesn't have a built-in one

module phy_model#(
	parameter int FRAME_BYTES = 104,
	parameter int IDLE_OFFSET = 24,
	parameter int PREAMBLE_OFFSET = 38,
	parameter int SFD_OFFSET = 40,
	parameter int TOTAL_CYCLES = SFD_OFFSET + FRAME_BYTES * 2,
	parameter string DATA_FILE = "C:/Users/andre/tick-to-trade/sim/data/data.hex"	
)

(
	output logic rx_clk,
	output logic [3:0] rx_dt,
	output logic rx_dt_valid,
	output logic rx_er	
);
	//25 MHz clock generator
	initial rx_clk = 1'b0;
	always #20 rx_clk = ~rx_clk;
	
	//States
	typedef enum logic[2:0]{
		IDLE,
		PREAMBLE,
		SFD,
		FRAME
	}byte_state_t;
	
	byte_state_t current_state;
	logic [$clog2(TOTAL_CYCLES):0] byte_idx;
	logic [7:0] frame_data [0:FRAME_BYTES - 1];
	
	//Set counter at the start
	//Read from hex file for input
	initial begin 
		byte_idx = 0;
		$readmemh(DATA_FILE, frame_data);
	end

	always_ff @(posedge rx_clk) begin
		//Cycle counter
		if(byte_idx < TOTAL_CYCLES - 1) begin
			byte_idx <= byte_idx + 1;
		end else begin
			byte_idx <= 0;
		end
	end

	always_comb begin
		//State transition logic
		if(byte_idx < IDLE_OFFSET) begin
                        current_state = IDLE;
                end else if(byte_idx < PREAMBLE_OFFSET) begin
                        current_state = PREAMBLE;
                end else if(byte_idx < SFD_OFFSET) begin
                        current_state = SFD;
                end else begin
                        current_state = FRAME;
                end
		
		//State output logic
		case(current_state)
			IDLE : begin
				rx_dt_valid = 0;
				rx_dt = 0;
			end
			PREAMBLE : begin 
				rx_dt_valid = 1;
				rx_dt = 4'h5;
			end
			SFD : begin
				rx_dt_valid = 1;
				if(byte_idx[0]) begin
			       		rx_dt = 4'hD;
				end 
				else begin
					rx_dt = 4'h5;
				end
			end
			FRAME : begin 
				rx_dt_valid = 1;
				if(byte_idx[0]) begin
					//byte_idx[0] is high when the second
					//part of the byte is being read and
					//vice versa
					rx_dt = frame_data[(byte_idx - SFD_OFFSET)/2][7:4];
				end else begin
					rx_dt = frame_data[(byte_idx - SFD_OFFSET)/2][3:0];
				end
			end
			default : begin
				rx_dt_valid = 0;
				rx_dt = 0;
			end
		endcase
	end

	//Assuming data is valid
	assign rx_er = 0;

endmodule
