// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vitch_framer.h for the primary calling header

#ifndef VERILATED_VITCH_FRAMER___024ROOT_H_
#define VERILATED_VITCH_FRAMER___024ROOT_H_  // guard

#include "verilated.h"
class Vitch_framer_itch_framer;


class Vitch_framer__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vitch_framer___024root final : public VerilatedModule {
  public:
    // CELLS
    Vitch_framer_itch_framer* itch_framer;

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
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vitch_framer__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vitch_framer___024root(Vitch_framer__Syms* symsp, const char* v__name);
    ~Vitch_framer___024root();
    VL_UNCOPYABLE(Vitch_framer___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
