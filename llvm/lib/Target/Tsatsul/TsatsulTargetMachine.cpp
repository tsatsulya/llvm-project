#include "TsatsulTargetMachine.h"
#include "Tsatsul.h"
#include "TargetInfo/TsatsulTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeTsatsulTarget() {
  // Register the target.
  TSATSUL_DUMP_CYAN
  RegisterTargetMachine<TsatsulTargetMachine> A(getTheTsatsulTarget());
}

TsatsulTargetMachine::TsatsulTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  TSATSUL_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// Tsatsul Code Generator Pass Configuration Options.
class TsatsulPassConfig : public TargetPassConfig {
public:
  TsatsulPassConfig(TsatsulTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  TsatsulTargetMachine &getTsatsulTargetMachine() const {
    return getTM<TsatsulTargetMachine>();
  }

  bool addInstSelector() override {
    TSATSUL_DUMP_CYAN
    addPass(createTsatsulISelDag(getTsatsulTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *TsatsulTargetMachine::createPassConfig(PassManagerBase &PM) {
  TSATSUL_DUMP_CYAN
  return new TsatsulPassConfig(*this, PM);
}

TargetLoweringObjectFile *TsatsulTargetMachine::getObjFileLowering() const {
  TSATSUL_DUMP_CYAN
  return TLOF.get();
}
