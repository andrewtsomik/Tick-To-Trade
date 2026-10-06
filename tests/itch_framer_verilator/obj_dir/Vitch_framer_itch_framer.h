// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vitch_framer.h for the primary calling header

#ifndef VERILATED_VITCH_FRAMER_ITCH_FRAMER_H_
#define VERILATED_VITCH_FRAMER_ITCH_FRAMER_H_  // guard

#include "verilated.h"


class Vitch_framer__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vitch_framer_itch_framer final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(itch_valid,0,0);
    VL_IN8(itch_byte,7,0);
    VL_IN8(start_of_boundary,0,0);
    VL_IN8(end_of_boundary,0,0);
    VL_OUT8(message_byte,7,0);
    VL_OUT8(valid,0,0);
    VL_OUT8(start_of_msg,0,0);
    VL_OUT8(end_of_msg,0,0);
    CData/*4:0*/ __PVT__itch_idx;
    CData/*0:0*/ __PVT__length_idx;
    CData/*0:0*/ __PVT__message_count_ready;
    CData/*2:0*/ state;
    CData/*2:0*/ __PVT__next_state;
    SData/*15:0*/ __PVT__message_count;
    SData/*15:0*/ __PVT__message_length;
    SData/*15:0*/ bytes_remaining;
    SData/*15:0*/ __PVT__messages_remaining;

    // INTERNAL VARIABLES
    Vitch_framer__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vitch_framer_itch_framer(Vitch_framer__Syms* symsp, const char* v__name);
    ~Vitch_framer_itch_framer();
    VL_UNCOPYABLE(Vitch_framer_itch_framer);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
