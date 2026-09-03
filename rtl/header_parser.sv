module header_parser#(
	parameter int MAX_FRAME_BYTES = 1518,

	parameter int DESTINATION_MAC_LEN = 6,
	parameter int ETHER_LEN = 2,
	parameter int VERSION_LEN = 1,
	parameter int IP_LEN = 1,
	parameter int UDP_LEN = 2,
	parameter int UDP_LENGTH_LEN = 2,
	
	parameter int DESTINATION_MAC_OFFSET = 6,
	parameter int ETHER_OFFSET = 14,
	parameter int VERSION_OFFSET = 15,
	parameter int IP_OFFSET = 24,
	parameter int UDP_OFFSET = 38,
	parameter int UDP_LENGTH_OFFSET = 40,

	parameter int ETHER_START = ETHER_OFFSET - ETHER_LEN,
	parameter int VERSION_START = VERSION_OFFSET - VERSION_LEN,
	parameter int IP_START = IP_OFFSET - IP_LEN,
	parameter int UDP_START = UDP_OFFSET - UDP_LEN,
	parameter int UDP_LENGTH_START = UDP_LENGTH_OFFSET - UDP_LENGTH_LEN,

	parameter int ITCH_START = 42
)
(
	input logic clk,
	input logic rst_n,
	input logic [7:0] rx_byte,
        input logic valid,
        input logic start_of_frame,
        input logic end_of_frame,
        input logic crc,

	output logic [7:0] itch_byte,
	output logic headers_valid,
	output logic itch_valid,
	output logic start_of_boundary,
	output logic end_of_boundary	
);

	logic [8 * DESTINATION_MAC_LEN - 1:0] destination_mac;
	logic [8 * ETHER_LEN - 1:0] ether_type;
	logic [8 * VERSION_LEN - 1:0] version;
	logic [8 * IP_LEN - 1:0] ip_protocol;
	logic [8 * UDP_LEN - 1:0] udp_destination;
	logic [8 * UDP_LENGTH_LEN - 1:0] udp_length;

	logic [$clog2(MAX_FRAME_BYTES)-1:0] byte_idx;

	always_ff @(posedge clk or negedge rst_n) begin 
		if(!rst_n || end_of_frame) begin 
			destination_mac <= 0;
			ether_type <= 0;
			version <= 0;
			ip_protocol <= 0;
			udp_destination <= 0;
			udp_length <= 0;
			byte_idx <= 0;
		end else if(valid) begin 
			if(byte_idx < DESTINATION_MAC_OFFSET) begin 
				destination_mac[8 * byte_idx +: 8] <= rx_byte;
			end else if(byte_idx < ETHER_OFFSET && byte_idx >= ETHER_START) begin
			        ether_type[8 * (byte_idx - ETHER_START) +: 8] <= rx_byte;
			end else if(byte_idx < VERSION_OFFSET) begin 
				version[8 * (byte_idx - VERSION_START) +: 8] <= rx_byte;
			end else if(byte_idx < IP_OFFSET && byte_idx >= IP_START) begin
				ip_protocol[8 * (byte_idx - IP_START) +: 8] <= rx_byte;
			end else if(byte_idx < UDP_OFFSET && byte_idx >= UDP_START) begin 
				udp_destination[8 * (byte_idx - UDP_START) +: 8] <= rx_byte;
			end else if(byte_idx < UDP_LENGTH_OFFSET) begin 
				udp_length[8 * (byte_idx - UDP_LENGTH_START) +: 8] <= rx_byte;
			end

			byte_idx <= byte_idx + 1;
		end
	end
	
	always_comb begin
		headers_valid = 0;
		if(destination_mac == 48'h02DEADBEEF02 && ether_type == 16'h0800 && version == 8'h45 && ip_protocol == 8'h11 && udp_destination == 16'hDEAF) begin 
			headers_valid = 1;
		end
	end

	assign start_of_boundary = (byte_idx == ITCH_START && headers_valid && valid) ? 1 : 0;
	assign end_of_boundary = (byte_idx == ITCH_START + udp_length - 9 && headers_valid && valid) ? 1 : 0;
	assign itch_valid = (byte_idx >= ITCH_START && valid && headers_valid && byte_idx < ITCH_START + udp_length - 8) ? 1 : 0;
	assign itch_byte = rx_byte;
endmodule
