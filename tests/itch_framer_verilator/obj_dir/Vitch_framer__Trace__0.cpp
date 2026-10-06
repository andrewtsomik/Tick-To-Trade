// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vitch_framer__Syms.h"


void Vitch_framer___024root__trace_chg_0_sub_0(Vitch_framer___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vitch_framer___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root__trace_chg_0\n"); );
    // Init
    Vitch_framer___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vitch_framer___024root*>(voidSelf);
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vitch_framer___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vitch_framer___024root__trace_chg_0_sub_0(Vitch_framer___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSymsp->TOP__itch_framer.__PVT__itch_idx),5);
        bufp->chgSData(oldp+1,(vlSymsp->TOP__itch_framer.__PVT__message_count),16);
        bufp->chgSData(oldp+2,(vlSymsp->TOP__itch_framer.__PVT__message_length),16);
        bufp->chgSData(oldp+3,(vlSymsp->TOP__itch_framer.__PVT__messages_remaining),16);
        bufp->chgBit(oldp+4,(vlSymsp->TOP__itch_framer.__PVT__length_idx));
        bufp->chgBit(oldp+5,(vlSymsp->TOP__itch_framer.__PVT__message_count_ready));
    }
    bufp->chgBit(oldp+6,(vlSelfRef.clk));
    bufp->chgBit(oldp+7,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+8,(vlSelfRef.itch_valid));
    bufp->chgCData(oldp+9,(vlSelfRef.itch_byte),8);
    bufp->chgBit(oldp+10,(vlSelfRef.start_of_boundary));
    bufp->chgBit(oldp+11,(vlSelfRef.end_of_boundary));
    bufp->chgCData(oldp+12,(vlSelfRef.message_byte),8);
    bufp->chgBit(oldp+13,(vlSelfRef.valid));
    bufp->chgBit(oldp+14,(vlSelfRef.start_of_msg));
    bufp->chgBit(oldp+15,(vlSelfRef.end_of_msg));
    bufp->chgBit(oldp+16,(vlSymsp->TOP__itch_framer.valid));
    bufp->chgBit(oldp+17,(((IData)(vlSymsp->TOP__itch_framer.valid) 
                           & ((IData)(vlSymsp->TOP__itch_framer.bytes_remaining) 
                              == (IData)(vlSymsp->TOP__itch_framer.__PVT__message_length)))));
    bufp->chgBit(oldp+18,(((IData)(vlSymsp->TOP__itch_framer.valid) 
                           & ((4U == (IData)(vlSymsp->TOP__itch_framer.__PVT__next_state)) 
                              | (2U == (IData)(vlSymsp->TOP__itch_framer.__PVT__next_state))))));
    bufp->chgSData(oldp+19,(vlSymsp->TOP__itch_framer.bytes_remaining),16);
    bufp->chgCData(oldp+20,(vlSymsp->TOP__itch_framer.state),3);
    bufp->chgCData(oldp+21,(vlSymsp->TOP__itch_framer.__PVT__next_state),3);
}

void Vitch_framer___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root__trace_cleanup\n"); );
    // Init
    Vitch_framer___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vitch_framer___024root*>(voidSelf);
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
