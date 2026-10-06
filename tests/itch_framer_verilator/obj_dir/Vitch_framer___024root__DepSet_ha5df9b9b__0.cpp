// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vitch_framer.h for the primary calling header

#include "Vitch_framer__pch.h"
#include "Vitch_framer__Syms.h"
#include "Vitch_framer___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vitch_framer___024root___dump_triggers__ico(Vitch_framer___024root* vlSelf);
#endif  // VL_DEBUG

void Vitch_framer___024root___eval_triggers__ico(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vitch_framer___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

void Vitch_framer___024root___ico_sequent__TOP__0(Vitch_framer___024root* vlSelf);
void Vitch_framer_itch_framer___ico_sequent__TOP__itch_framer__0(Vitch_framer_itch_framer* vlSelf);
void Vitch_framer___024root___ico_sequent__TOP__1(Vitch_framer___024root* vlSelf);

void Vitch_framer___024root___eval_ico(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vitch_framer___024root___ico_sequent__TOP__0(vlSelf);
        Vitch_framer_itch_framer___ico_sequent__TOP__itch_framer__0((&vlSymsp->TOP__itch_framer));
        Vitch_framer___024root___ico_sequent__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vitch_framer___024root___ico_sequent__TOP__1(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___ico_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.valid = vlSymsp->TOP__itch_framer.valid;
    vlSelfRef.end_of_msg = ((IData)(vlSymsp->TOP__itch_framer.valid) 
                            & ((4U == (IData)(vlSymsp->TOP__itch_framer.__PVT__next_state)) 
                               | (2U == (IData)(vlSymsp->TOP__itch_framer.__PVT__next_state))));
    vlSelfRef.start_of_msg = ((IData)(vlSymsp->TOP__itch_framer.valid) 
                              & ((IData)(vlSymsp->TOP__itch_framer.bytes_remaining) 
                                 == (IData)(vlSymsp->TOP__itch_framer.__PVT__message_length)));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vitch_framer___024root___dump_triggers__act(Vitch_framer___024root* vlSelf);
#endif  // VL_DEBUG

void Vitch_framer___024root___eval_triggers__act(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSelfRef.rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vitch_framer___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vitch_framer_itch_framer___nba_sequent__TOP__itch_framer__0(Vitch_framer_itch_framer* vlSelf);

void Vitch_framer___024root___eval_nba(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vitch_framer_itch_framer___nba_sequent__TOP__itch_framer__0((&vlSymsp->TOP__itch_framer));
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
        Vitch_framer___024root___ico_sequent__TOP__1(vlSelf);
    }
}
