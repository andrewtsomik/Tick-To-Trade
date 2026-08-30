module tb_phy;

logic rx_clk;
logic [3:0] rx_dt;
logic rx_dt_valid;
logic rx_er;

phy_model#(
	.FRAME_BYTES(4),
	.DATA_FILE("C:/Users/andre/tick-to-trade/sim/data/data.hex")	
) dut (.*);

initial #10000 $finish;

endmodule
