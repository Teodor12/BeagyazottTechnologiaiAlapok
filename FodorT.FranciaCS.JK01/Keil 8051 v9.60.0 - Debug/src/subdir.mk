################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/SILABS_STARTUP.A51 

C_SRCS += \
../src/Display.c \
../src/InitDevice.c \
../src/Interrupts.c \
../src/main.c 

OBJS += \
./src/Display.OBJ \
./src/InitDevice.OBJ \
./src/Interrupts.OBJ \
./src/SILABS_STARTUP.OBJ \
./src/main.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/Display.OBJ: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/Users/Teodor/Desktop/FodorT.FranciaCS.JK01/inc/Display.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/stdbool.h

src/InitDevice.OBJ: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/Users/Teodor/Desktop/FodorT.FranciaCS.JK01/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/stdbool.h

src/Interrupts.OBJ: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/LIMITS.H C:/Users/Teodor/Desktop/FodorT.FranciaCS.JK01/inc/Display.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/stdbool.h

src/SILABS_STARTUP.OBJ: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/SILABS_STARTUP.A51 src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/main.OBJ: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/Users/Teodor/Desktop/FodorT.FranciaCS.JK01/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/stdbool.h C:/Users/Teodor/Desktop/FodorT.FranciaCS.JK01/inc/Display.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.5/Device/shared/si8051Base/si_toolchain.h


