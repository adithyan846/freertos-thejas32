################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/port.c 

S_UPPER_SRCS += \
../FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/portasm.S 

OBJS += \
./FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/port.o \
./FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/portasm.o 

S_UPPER_DEPS += \
./FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/portasm.d 

C_DEPS += \
./FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/%.o: ../FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/%.c FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_Source/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_Source/portable/GCC/RISC-V" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/Common/include" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/%.o: ../FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/%.S FreeRTOS_Source/portable/CodeWarrior/ColdFire_V2/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -x assembler-with-cpp -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_Source/portable/GCC/RISC-V/chip_specific_extensions/VEGA-THEJA32-ARIES" -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


