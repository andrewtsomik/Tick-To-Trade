// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vitch_framer__pch.h"
#include "Vitch_framer.h"
#include "Vitch_framer___024root.h"
#include "Vitch_framer_itch_framer.h"

// FUNCTIONS
Vitch_framer__Syms::~Vitch_framer__Syms()
{
}

Vitch_framer__Syms::Vitch_framer__Syms(VerilatedContext* contextp, const char* namep, Vitch_framer* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__itch_framer{this, Verilated::catName(namep, "itch_framer")}
{
        // Check resources
        Verilated::stackCheck(47);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.itch_framer = &TOP__itch_framer;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__itch_framer.__Vconfigure(true);
    // Setup scopes
    __Vscope_itch_framer.configure(this, name(), "itch_framer", "itch_framer", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_itch_framer.varInsert(__Vfinal,"bytes_remaining", &(TOP__itch_framer.bytes_remaining), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_itch_framer.varInsert(__Vfinal,"state", &(TOP__itch_framer.state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
    }
}
