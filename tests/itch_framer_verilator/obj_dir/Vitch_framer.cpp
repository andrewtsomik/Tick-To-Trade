// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vitch_framer__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vitch_framer::Vitch_framer(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vitch_framer__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , itch_valid{vlSymsp->TOP.itch_valid}
    , itch_byte{vlSymsp->TOP.itch_byte}
    , start_of_boundary{vlSymsp->TOP.start_of_boundary}
    , end_of_boundary{vlSymsp->TOP.end_of_boundary}
    , message_byte{vlSymsp->TOP.message_byte}
    , valid{vlSymsp->TOP.valid}
    , start_of_msg{vlSymsp->TOP.start_of_msg}
    , end_of_msg{vlSymsp->TOP.end_of_msg}
    , itch_framer{vlSymsp->TOP.itch_framer}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vitch_framer::Vitch_framer(const char* _vcname__)
    : Vitch_framer(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vitch_framer::~Vitch_framer() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vitch_framer___024root___eval_debug_assertions(Vitch_framer___024root* vlSelf);
#endif  // VL_DEBUG
void Vitch_framer___024root___eval_static(Vitch_framer___024root* vlSelf);
void Vitch_framer___024root___eval_initial(Vitch_framer___024root* vlSelf);
void Vitch_framer___024root___eval_settle(Vitch_framer___024root* vlSelf);
void Vitch_framer___024root___eval(Vitch_framer___024root* vlSelf);

void Vitch_framer::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vitch_framer::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vitch_framer___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vitch_framer___024root___eval_static(&(vlSymsp->TOP));
        Vitch_framer___024root___eval_initial(&(vlSymsp->TOP));
        Vitch_framer___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vitch_framer___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vitch_framer::eventsPending() { return false; }

uint64_t Vitch_framer::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vitch_framer::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vitch_framer___024root___eval_final(Vitch_framer___024root* vlSelf);

VL_ATTR_COLD void Vitch_framer::final() {
    Vitch_framer___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vitch_framer::hierName() const { return vlSymsp->name(); }
const char* Vitch_framer::modelName() const { return "Vitch_framer"; }
unsigned Vitch_framer::threads() const { return 1; }
void Vitch_framer::prepareClone() const { contextp()->prepareClone(); }
void Vitch_framer::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vitch_framer::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vitch_framer___024root__trace_decl_types(VerilatedVcd* tracep);

void Vitch_framer___024root__trace_init_top(Vitch_framer___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vitch_framer___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vitch_framer___024root*>(voidSelf);
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vitch_framer___024root__trace_decl_types(tracep);
    Vitch_framer___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vitch_framer___024root__trace_register(Vitch_framer___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vitch_framer::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vitch_framer::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vitch_framer___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
