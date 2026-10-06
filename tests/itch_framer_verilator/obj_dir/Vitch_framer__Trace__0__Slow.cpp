// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vitch_framer__Syms.h"


VL_ATTR_COLD void Vitch_framer___024root__trace_init_sub__TOP__itch_framer__0(Vitch_framer___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vitch_framer___024root__trace_init_sub__TOP__0(Vitch_framer___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root__trace_init_sub__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("itch_framer", VerilatedTracePrefixType::SCOPE_MODULE);
    Vitch_framer___024root__trace_init_sub__TOP__itch_framer__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+7,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"itch_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"itch_byte",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+11,0,"start_of_boundary",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"end_of_boundary",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"message_byte",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+14,0,"valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"start_of_msg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"end_of_msg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vitch_framer___024root__trace_init_sub__TOP__itch_framer__0(Vitch_framer___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root__trace_init_sub__TOP__itch_framer__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+23,0,"MOLD_MESSAGE_COUNT_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+24,0,"MOLD_MESSAGE_COUNT_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+25,0,"MESSAGE_LENGTH_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+24,0,"MESSAGE_LENGTH_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+26,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+7,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"itch_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"itch_byte",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+11,0,"start_of_boundary",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"end_of_boundary",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"message_byte",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+17,0,"valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"start_of_msg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"end_of_msg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"itch_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+2,0,"message_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"message_length",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+20,0,"bytes_remaining",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"messages_remaining",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+5,0,"length_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"message_count_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+22,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
}

VL_ATTR_COLD void Vitch_framer___024root__trace_init_top(Vitch_framer___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root__trace_init_top\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vitch_framer___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vitch_framer___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vitch_framer___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vitch_framer___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vitch_framer___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vitch_framer___024root__trace_register(Vitch_framer___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root__trace_register\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vitch_framer___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vitch_framer___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vitch_framer___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vitch_framer___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vitch_framer___024root__trace_const_0_sub_0(Vitch_framer___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vitch_framer___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root__trace_const_0\n"); );
    // Init
    Vitch_framer___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vitch_framer___024root*>(voidSelf);
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vitch_framer___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vitch_framer___024root__trace_const_0_sub_0(Vitch_framer___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root__trace_const_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+23,(0x12U),32);
    bufp->fullIData(oldp+24,(2U),32);
    bufp->fullIData(oldp+25,(0x14U),32);
    bufp->fullIData(oldp+26,(8U),32);
}

VL_ATTR_COLD void Vitch_framer___024root__trace_full_0_sub_0(Vitch_framer___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vitch_framer___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root__trace_full_0\n"); );
    // Init
    Vitch_framer___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vitch_framer___024root*>(voidSelf);
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vitch_framer___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vitch_framer___024root__trace_full_0_sub_0(Vitch_framer___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitch_framer___024root__trace_full_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSymsp->TOP__itch_framer.__PVT__itch_idx),5);
    bufp->fullSData(oldp+2,(vlSymsp->TOP__itch_framer.__PVT__message_count),16);
    bufp->fullSData(oldp+3,(vlSymsp->TOP__itch_framer.__PVT__message_length),16);
    bufp->fullSData(oldp+4,(vlSymsp->TOP__itch_framer.__PVT__messages_remaining),16);
    bufp->fullBit(oldp+5,(vlSymsp->TOP__itch_framer.__PVT__length_idx));
    bufp->fullBit(oldp+6,(vlSymsp->TOP__itch_framer.__PVT__message_count_ready));
    bufp->fullBit(oldp+7,(vlSelfRef.clk));
    bufp->fullBit(oldp+8,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+9,(vlSelfRef.itch_valid));
    bufp->fullCData(oldp+10,(vlSelfRef.itch_byte),8);
    bufp->fullBit(oldp+11,(vlSelfRef.start_of_boundary));
    bufp->fullBit(oldp+12,(vlSelfRef.end_of_boundary));
    bufp->fullCData(oldp+13,(vlSelfRef.message_byte),8);
    bufp->fullBit(oldp+14,(vlSelfRef.valid));
    bufp->fullBit(oldp+15,(vlSelfRef.start_of_msg));
    bufp->fullBit(oldp+16,(vlSelfRef.end_of_msg));
    bufp->fullBit(oldp+17,(vlSymsp->TOP__itch_framer.valid));
    bufp->fullBit(oldp+18,(((IData)(vlSymsp->TOP__itch_framer.valid) 
                            & ((IData)(vlSymsp->TOP__itch_framer.bytes_remaining) 
                               == (IData)(vlSymsp->TOP__itch_framer.__PVT__message_length)))));
    bufp->fullBit(oldp+19,(((IData)(vlSymsp->TOP__itch_framer.valid) 
                            & ((4U == (IData)(vlSymsp->TOP__itch_framer.__PVT__next_state)) 
                               | (2U == (IData)(vlSymsp->TOP__itch_framer.__PVT__next_state))))));
    bufp->fullSData(oldp+20,(vlSymsp->TOP__itch_framer.bytes_remaining),16);
    bufp->fullCData(oldp+21,(vlSymsp->TOP__itch_framer.state),3);
    bufp->fullCData(oldp+22,(vlSymsp->TOP__itch_framer.__PVT__next_state),3);
}
