// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vitch_framer.h for the primary calling header

#include "Vitch_framer__pch.h"
#include "Vitch_framer__Syms.h"
#include "Vitch_framer___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vitch_framer___024root___dump_triggers__stl(Vitch_framer___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vitch_framer___024root___eval_triggers__stl(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vitch_framer___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void Vitch_framer___024root___ico_sequent__TOP__0(Vitch_framer___024root* vlSelf);
void Vitch_framer_itch_framer___ico_sequent__TOP__itch_framer__0(Vitch_framer_itch_framer* vlSelf);
void Vitch_framer___024root___ico_sequent__TOP__1(Vitch_framer___024root* vlSelf);

VL_ATTR_COLD void Vitch_framer___024root___eval_stl(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vitch_framer___024root___ico_sequent__TOP__0(vlSelf);
        Vitch_framer_itch_framer___ico_sequent__TOP__itch_framer__0((&vlSymsp->TOP__itch_framer));
        Vitch_framer___024root___ico_sequent__TOP__1(vlSelf);
    }
}
