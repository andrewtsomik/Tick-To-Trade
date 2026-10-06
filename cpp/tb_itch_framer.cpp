#include "Vitch_framer.h"
#include "Vitch_framer_itch_framer.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <vector>
#include <cstdio>

Vitch_framer* dut;
VerilatedVcdC* trace;
vluint64_t sim_time = 0;

std::vector<uint8_t> received;
int sof_count = 0, eof_count = 0;
int errors = 0;

void tick() {
    dut->clk = 0; 
    dut->eval();
    trace->dump(sim_time++);
    
    dut->clk = 1;
    printf("t=%llu state=%d br=%d sof=%d eof=%d valid=%d\n",
       sim_time, dut->itch_framer->state,
       dut->itch_framer->bytes_remaining,
       dut->start_of_msg, dut->end_of_msg, dut->valid); 
    dut->eval();
    trace->dump(sim_time++);

    
    if (dut->valid) {
    	received.push_back(dut->message_byte);
    }
    if (dut->start_of_msg) {
    	sof_count++;
    }
    if (dut->end_of_msg) {
    	eof_count++;
    }
}

void send_byte(uint8_t b) {
    dut->itch_byte  = b;
    dut->itch_valid = 1;
    tick();
    dut->itch_valid = 0;
}

void send_mold_header(uint16_t count) {
    for (int i = 0; i < 18; i++) { 
    	send_byte(0x00);
    }
    send_byte(count >> 8);
    send_byte(count & 0xFF);
}

void send_length(uint16_t len) {
    send_byte(len >> 8);
    send_byte(len & 0xFF);
}

void send_message(int len, uint8_t first) {
    for (int i = 0; i < len; i++) {
	send_byte(first + i);
    }
}

void do_reset() {
    dut->rst_n = 0;
    dut->itch_valid = 0;
    dut->start_of_boundary = 0;
    dut->end_of_boundary = 0;
    for (int i = 0; i < 3; i++) {
	tick();
    }
    dut->rst_n = 1;
}

void check(const char* name, bool pass) {
    printf("[%s] %s\n", pass ? "pass" : "FAIL", name);
    if (!pass) {
	errors++;
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vitch_framer;
    trace = new VerilatedVcdC;
    dut->trace(trace, 5);
    trace->open("itch_framer.vcd");

    do_reset();
    received.clear();
    
    sof_count = eof_count = 0;

    dut->start_of_boundary = 1;
    send_mold_header(1);
    dut->start_of_boundary = 0;
    send_length(36);
    send_message(36, 0x10);
    dut->end_of_boundary = 1;
    tick();
    dut->end_of_boundary = 0;

    check("single message: 36 bytes out", received.size() == 36);
    check("single message: one sof",      sof_count == 1);
    check("single message: one eof",      eof_count == 1);
    
    printf("  eof_count = %d, sof_count = %d, bytes = %zu remaining bytes = %d\n", eof_count, sof_count, received.size(), dut->itch_framer->bytes_remaining);

    printf(errors ? "=== %d FAILURE(S) ===\n" : "=== ALL PASS ===\n", errors);
    trace->close();
    delete dut;
    return errors != 0;
}
