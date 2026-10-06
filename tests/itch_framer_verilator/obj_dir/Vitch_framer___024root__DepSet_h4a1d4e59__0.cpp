// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vitch_framer.h for the primary calling header

#include "Vitch_framer__pch.h"
#include "Vitch_framer___024root.h"

VL_INLINE_OPT void Vitch_framer___024root___ico_sequent__TOP__0(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.message_byte = vlSelfRef.itch_byte;
}

void Vitch_framer___024root___eval_triggers__ico(Vitch_framer___024root* vlSelf);
void Vitch_framer___024root___eval_ico(Vitch_framer___024root* vlSelf);

bool Vitch_framer___024root___eval_phase__ico(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval_phase__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vitch_framer___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vitch_framer___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vitch_framer___024root___eval_act(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vitch_framer___024root___eval_triggers__act(Vitch_framer___024root* vlSelf);

bool Vitch_framer___024root___eval_phase__act(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vitch_framer___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vitch_framer___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vitch_framer___024root___eval_nba(Vitch_framer___024root* vlSelf);

bool Vitch_framer___024root___eval_phase__nba(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vitch_framer___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vitch_framer___024root___dump_triggers__ico(Vitch_framer___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vitch_framer___024root___dump_triggers__nba(Vitch_framer___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vitch_framer___024root___dump_triggers__act(Vitch_framer___024root* vlSelf);
#endif  // VL_DEBUG

void Vitch_framer___024root___eval(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vitch_framer___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/atsomik/Tick-To-Trade/rtl/itch_framer.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vitch_framer___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vitch_framer___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/atsomik/Tick-To-Trade/rtl/itch_framer.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vitch_framer___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/atsomik/Tick-To-Trade/rtl/itch_framer.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vitch_framer___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vitch_framer___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vitch_framer___024root___eval_debug_assertions(Vitch_framer___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelfRef.itch_valid & 0xfeU))) {
        Verilated::overWidthError("itch_valid");}
    if (VL_UNLIKELY((vlSelfRef.start_of_boundary & 0xfeU))) {
        Verilated::overWidthError("start_of_boundary");}
    if (VL_UNLIKELY((vlSelfRef.end_of_boundary & 0xfeU))) {
        Verilated::overWidthError("end_of_boundary");}
}
#endif  // VL_DEBUG
