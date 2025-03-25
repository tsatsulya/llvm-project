add_llvm_component_library(LLVMTsatsulDesc
  TsatsulMCTargetDesc.cpp
  TsatsulMCAsmInfo.cpp
  TsatsulInstPrinter.cpp

  LINK_COMPONENTS
  MC
  Support
  TsatsulInfo

  ADD_TO_COMPONENT
  Tsatsul
 )
