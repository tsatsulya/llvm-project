#ifndef LLVM_LIB_TARGET_TSATSUL_MCTARGETDESC_TSATSULMCASMINFO_H
#define LLVM_LIB_TARGET_TSATSUL_MCTARGETDESC_TSATSULMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class TsatsulELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit TsatsulELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_TSATSUL_MCTARGETDESC_TSATSULMCASMINFO_H