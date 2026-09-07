module async_fifo#(
	parameter int DATA_WIDTH = 5,
	parameter int FIFO_DEPTH = 8,
	parameter int ADDR_WIDTH = $clog2(FIFO_DEPTH)
)
(
	input logic phy_clk,
	input logic mac_clk,
	input logic phy_rst_n,
	input logic mac_rst_n,
	input logic wr_en,
	input logic rd_en,
	input logic [DATA_WIDTH-1:0] data_in,
	
	output logic full,
	output logic empty,
	output logic [DATA_WIDTH-1:0] data_out,

	output logic [15:0] drop_cnt
);

	logic [DATA_WIDTH-1:0] mem [0:FIFO_DEPTH-1];
	logic [ADDR_WIDTH:0] wr_ptr_bin;
	logic [ADDR_WIDTH:0] rd_ptr_bin;
	
	logic [ADDR_WIDTH:0] wr_ptr_gray;
	logic [ADDR_WIDTH:0] rd_ptr_gray;

	logic [ADDR_WIDTH:0] wr_ptr_next;
	logic [ADDR_WIDTH:0] rd_ptr_next;
	
	logic [ADDR_WIDTH:0] wr_ptr_sync1;
	logic [ADDR_WIDTH:0] wr_ptr_sync2;
	logic [ADDR_WIDTH:0] rd_ptr_sync1;
	logic [ADDR_WIDTH:0] rd_ptr_sync2;

	always_ff @(posedge phy_clk or negedge phy_rst_n) begin 
		if(!phy_rst_n) begin 
			wr_ptr_bin <= 0;
			wr_ptr_gray <= 0;
		end else if(wr_en && !full) begin 
			wr_ptr_bin <= wr_ptr_next;
			wr_ptr_gray <= wr_ptr_next ^ (wr_ptr_next >> 1);
			mem[wr_ptr_bin[ADDR_WIDTH-1:0]] <= data_in;
		end
	end

	always_ff @(posedge mac_clk or negedge mac_rst_n) begin 
		if(!mac_rst_n) begin 
			rd_ptr_bin <= 0;
			rd_ptr_gray <= 0;
		end else if(rd_en && !empty) begin 
			rd_ptr_bin <= rd_ptr_next;
			rd_ptr_gray <= rd_ptr_next ^ (rd_ptr_next >> 1);
		end
	end

	always_ff @(posedge phy_clk or negedge phy_rst_n) begin 
		if(!phy_rst_n) begin 
			rd_ptr_sync1 <= 0;
			rd_ptr_sync2 <= 0;
		end else begin 
			rd_ptr_sync1 <= rd_ptr_gray;
			rd_ptr_sync2 <= rd_ptr_sync1;
		end
	end

	always_ff @(posedge mac_clk or negedge mac_rst_n) begin 
		if(!mac_rst_n) begin 
			wr_ptr_sync1 <= 0;
			wr_ptr_sync2 <= 0;
		end else begin 
			wr_ptr_sync1 <= wr_ptr_gray;
			wr_ptr_sync2 <= wr_ptr_sync1;
		end
	end

	always_ff @(posedge phy_clk or negedge phy_rst_n) begin 
		if(!phy_rst_n) begin 
			drop_cnt <= 0;
		end else if (wr_en && full) begin 
			drop_cnt <= drop_cnt + 1;
		end
	end

	always_comb begin 
		wr_ptr_next = wr_ptr_bin + 1;
		rd_ptr_next = rd_ptr_bin + 1;

		data_out = mem[rd_ptr_bin[ADDR_WIDTH-1:0]];

		empty = rd_ptr_gray == wr_ptr_sync2;
		
		full = wr_ptr_gray == {~rd_ptr_sync2[ADDR_WIDTH:ADDR_WIDTH-1], rd_ptr_sync2[ADDR_WIDTH-2:0]};
	end


endmodule
