add_llvm_component_group(Tsatsul)

set(LLVM_TARGET_DEFINITIONS Tsatsul.td)

tablegen(LLVM TsatsulGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM TsatsulGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM TsatsulGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM TsatsulGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM TsatsulGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM TsatsulGenCallingConv.inc -gen-callingconv)
tablegen(LLVM TsatsulGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM TsatsulGenMCCodeEmitter.inc -gen-emitter)

add_public_tablegen_target(TsatsulCommonTableGen)

add_llvm_target(TsatsulCodeGen
  TsatsulTargetMachine.cpp
  TsatsulRegisterInfo.cpp
  TsatsulInstrInfo.cpp
  TsatsulSubtarget.cpp
  TsatsulAsmPrinter.cpp
  TsatsulISelDagToDag.cpp
  TsatsulISelLowering.cpp
  TsatsulMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  TsatsulInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  Tsatsul
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
