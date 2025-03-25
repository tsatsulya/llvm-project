#include "TargetInfo/TsatsulTargetInfo.h"
#include "Tsatsul.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheTsatsulTarget() {
  TSATSUL_DUMP_YELLOW
  static Target TheTsatsulTarget;
  return TheTsatsulTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeTsatsulTargetInfo() {
  TSATSUL_DUMP_YELLOW
  RegisterTarget<Triple::tsatsul> X(getTheTsatsulTarget(), "tsatsul",
                                "TSATSULulator target for LLVM course :D", "TSATSUL");
}
