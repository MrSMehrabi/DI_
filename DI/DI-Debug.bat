@echo off
REM Run this file to build the project outside of the IDE.
REM WARNING: if using a different machine, copy the .rsp files together with this script.
echo stm32f7xx_hal_gpio.c
C:\SysGCC\arm-eabi\bin\arm-none-eabi-gcc.exe @"VisualGDB/Debug/stm32f7xx_hal_gpio.gcc.rsp" || exit 1
echo stm32f7xx_hal_rcc.c
C:\SysGCC\arm-eabi\bin\arm-none-eabi-gcc.exe @"VisualGDB/Debug/stm32f7xx_hal_rcc.gcc.rsp" || exit 1
echo Source.cpp
C:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/Source.gcc.rsp" || exit 1
echo startup_stm32f746xx.c
C:\SysGCC\arm-eabi\bin\arm-none-eabi-gcc.exe @"VisualGDB/Debug/startup_stm32f746xx.gcc.rsp" || exit 1
echo Linking ../VisualGDB/Debug/DI...
C:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @../VisualGDB/Debug/DI.link.rsp || exit 1
C:\SysGCC\arm-eabi\bin\arm-none-eabi-objcopy.exe @../VisualGDB/Debug/DI.mkbin.rsp || exit 1
C:\SysGCC\arm-eabi\bin\arm-none-eabi-objcopy.exe @../VisualGDB/Debug/DI.mkihex.rsp || exit 1
