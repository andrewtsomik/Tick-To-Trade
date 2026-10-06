// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vitch_framer.h for the primary calling header

#include "Vitch_framer__pch.h"
#include "Vitch_framer__Syms.h"
#include "Vitch_framer_itch_framer.h"

void Vitch_framer_itch_framer___ctor_var_reset(Vitch_framer_itch_framer* vlSelf);

Vitch_framer_itch_framer::Vitch_framer_itch_framer(Vitch_framer__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vitch_framer_itch_framer___ctor_var_reset(this);
}

void Vitch_framer_itch_framer::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vitch_framer_itch_framer::~Vitch_framer_itch_framer() {
}
