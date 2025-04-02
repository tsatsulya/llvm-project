#include "MCTargetDesc/TsatsulInfo.h"
#include "Tsatsul.h"
#include "TsatsulInstPrinter.h"
#include "TsatsulMCAsmInfo.h"
#include "TargetInfo/TsatsulTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "TsatsulGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "TsatsulGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "TsatsulGenSubtargetInfo.inc"

static MCRegisterInfo *createTsatsulMCRegisterInfo(const Triple &TT) {
  TSATSUL_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitTsatsulMCRegisterInfo(X, Tsatsul::R0);
  return X;
}

static MCInstrInfo *createTsatsulMCInstrInfo() {
  TSATSUL_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitTsatsulMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createTsatsulMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  TSATSUL_DUMP_MAGENTA
  return createTsatsulMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createTsatsulMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  TSATSUL_DUMP_MAGENTA
  MCAsmInfo *MAI = new TsatsulELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(Tsatsul::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createTsatsulMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  TSATSUL_DUMP_MAGENTA
  return new TsatsulInstPrinter(MAI, MII, MRI);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeTsatsulTargetMC() {
  TSATSUL_DUMP_MAGENTA
  Target &TheTsatsulTarget = getTheTsatsulTarget();
  RegisterMCAsmInfoFn X(TheTsatsulTarget, createTsatsulMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheTsatsulTarget, createTsatsulMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheTsatsulTarget, createTsatsulMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheTsatsulTarget,
                                          createTsatsulMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheTsatsulTarget, createTsatsulMCInstPrinter);
  // Register the MC Code Emitter.
  TargetRegistry::RegisterMCCodeEmitter(TheTsatsulTarget, createTsatsulMCCodeEmitter);
  // Register the asm backend.
  TargetRegistry::RegisterMCAsmBackend(TheTsatsulTarget, createTsatsulAsmBackend);
}
