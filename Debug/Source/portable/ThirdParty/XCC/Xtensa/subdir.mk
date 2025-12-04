################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/portable/ThirdParty/XCC/Xtensa/port.c \
../Source/portable/ThirdParty/XCC/Xtensa/portclib.c \
../Source/portable/ThirdParty/XCC/Xtensa/xtensa_init.c \
../Source/portable/ThirdParty/XCC/Xtensa/xtensa_intr.c \
../Source/portable/ThirdParty/XCC/Xtensa/xtensa_overlay_os_hook.c 

S_UPPER_SRCS += \
../Source/portable/ThirdParty/XCC/Xtensa/portasm.S \
../Source/portable/ThirdParty/XCC/Xtensa/xtensa_context.S \
../Source/portable/ThirdParty/XCC/Xtensa/xtensa_intr_asm.S \
../Source/portable/ThirdParty/XCC/Xtensa/xtensa_vectors.S 

OBJS += \
./Source/portable/ThirdParty/XCC/Xtensa/port.o \
./Source/portable/ThirdParty/XCC/Xtensa/portasm.o \
./Source/portable/ThirdParty/XCC/Xtensa/portclib.o \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_context.o \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_init.o \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_intr.o \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_intr_asm.o \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_overlay_os_hook.o \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_vectors.o 

S_UPPER_DEPS += \
./Source/portable/ThirdParty/XCC/Xtensa/portasm.d \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_context.d \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_intr_asm.d \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_vectors.d 

C_DEPS += \
./Source/portable/ThirdParty/XCC/Xtensa/port.d \
./Source/portable/ThirdParty/XCC/Xtensa/portclib.d \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_init.d \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_intr.d \
./Source/portable/ThirdParty/XCC/Xtensa/xtensa_overlay_os_hook.d 


# Each subdirectory must supply rules for building sources it contributes
Source/portable/ThirdParty/XCC/Xtensa/%.o: ../Source/portable/ThirdParty/XCC/Xtensa/%.c Source/portable/ThirdParty/XCC/Xtensa/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/Source/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/Source/portable/GCC/RISC-V" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/portable/ThirdParty/XCC/Xtensa/%.o: ../Source/portable/ThirdParty/XCC/Xtensa/%.S Source/portable/ThirdParty/XCC/Xtensa/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -x assembler-with-cpp -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


