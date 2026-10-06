// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vitch_framer.h for the primary calling header

#include "Vitch_framer__pch.h"
#include "Vitch_framer_itch_framer.h"

VL_ATTR_COLD void Vitch_framer_itch_framer___ctor_var_reset(Vitch_framer_itch_framer* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vitch_framer_itch_framer___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->itch_valid = VL_RAND_RESET_I(1);
    vlSelf->itch_byte = VL_RAND_RESET_I(8);
    vlSelf->start_of_boundary = VL_RAND_RESET_I(1);
    vlSelf->end_of_boundary = VL_RAND_RESET_I(1);
    vlSelf->message_byte = VL_RAND_RESET_I(8);
    vlSelf->valid = VL_RAND_RESET_I(1);
    vlSelf->start_of_msg = VL_RAND_RESET_I(1);
    vlSelf->end_of_msg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__itch_idx = VL_RAND_RESET_I(5);
    vlSelf->__PVT__message_count = VL_RAND_RESET_I(16);
    vlSelf->__PVT__message_length = VL_RAND_RESET_I(16);
    vlSelf->bytes_remaining = VL_RAND_RESET_I(16);
    vlSelf->__PVT__messages_remaining = VL_RAND_RESET_I(16);
    vlSelf->__PVT__length_idx = VL_RAND_RESET_I(1);
    vlSelf->__PVT__message_count_ready = VL_RAND_RESET_I(1);
    vlSelf->state = VL_RAND_RESET_I(3);
    vlSelf->__PVT__next_state = VL_RAND_RESET_I(3);
}
