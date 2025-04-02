add_llvm_component_library(LLVMTsatsulDesc
  TsatsulMCTargetDesc.cpp
  TsatsulMCAsmInfo.cpp
  TsatsulInstPrinter.cpp
  TsatsulMCCodeEmitter.cpp
  TsatsulAsmBackend.cpp
  TsatsulELFObjectWriter.cpp

  LINK_COMPONENTS
  MC
  Support
  TsatsulInfo

  ADD_TO_COMPONENT
  Tsatsul
 )
