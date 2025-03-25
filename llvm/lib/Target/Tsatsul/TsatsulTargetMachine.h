#ifndef LLVM_LIB_TARGET_TSATSUL_TSATSULTARGETMACHINE_H
#define LLVM_LIB_TARGET_TSATSUL_TSATSULTARGETMACHINE_H

#include "TsatsulSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheTsatsulTarget;

class TsatsulTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  TsatsulSubtarget Subtarget;

public:
  TsatsulTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const TsatsulSubtarget *getSubtargetImpl(const Function &) const override {
    TSATSUL_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_TSATSUL_TSATSULTARGETMACHINE_H
