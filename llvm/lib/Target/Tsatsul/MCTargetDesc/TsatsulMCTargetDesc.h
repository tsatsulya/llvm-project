#ifndef LLVM_LIB_TARGET_TSATSUL_MCTARGETDESC_TSATSULMCTARGETDESC_H
#define LLVM_LIB_TARGET_TSATSUL_MCTARGETDESC_TSATSULMCTARGETDESC_H

#include <memory>
namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createTsatsulMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createTsatsulAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter> createTsatsulELFObjectWriter(bool Is64Bit,
                                                               uint8_t OSABI);
} // namespace llvm

// Defines symbolic names for Tsatsul registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "TsatsulGenRegisterInfo.inc"

// Defines symbolic names for the Tsatsul instructions.
#define GET_INSTRINFO_ENUM
#include "TsatsulGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_TSATSUL_MCTARGETDESC_TSATSULMCTARGETDESC_H
