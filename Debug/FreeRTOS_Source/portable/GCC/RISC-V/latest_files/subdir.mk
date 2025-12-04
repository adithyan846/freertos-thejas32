################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/hdg/Documents/freertos_thejas32/Source/portable/GCC/RISC-V/latest_files/port.c 

S_UPPER_SRCS += \
/home/hdg/Documents/freertos_thejas32/Source/portable/GCC/RISC-V/latest_files/portASM.S 

OBJS += \
./FreeRTOS_Source/portable/GCC/RISC-V/latest_files/port.o \
./FreeRTOS_Source/portable/GCC/RISC-V/latest_files/portASM.o 

S_UPPER_DEPS += \
./FreeRTOS_Source/portable/GCC/RISC-V/latest_files/portASM.d 

C_DEPS += \
./FreeRTOS_Source/portable/GCC/RISC-V/latest_files/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Source/portable/GCC/RISC-V/latest_files/port.o: /home/hdg/Documents/freertos_thejas32/Source/portable/GCC/RISC-V/latest_files/port.c FreeRTOS_Source/portable/GCC/RISC-V/latest_files/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/Documents/freertos_thejas32/Source/include" -I"/home/hdg/Documents/freertos_thejas32/Source/portable/GCC/RISC-V" -I"/home/hdg/Documents/freertos_thejas32/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/Documents/freertos_thejas32/RISC-V_CDAC_THEJAS32" -I"/home/hdg/Documents/freertos_thejas32/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/Documents/freertos_thejas32/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/Documents/freertos_thejas32/Common/include" -I"/home/hdg/Documents/freertos_thejas32/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/Documents/freertos_thejas32/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS_Source/portable/GCC/RISC-V/latest_files/portASM.o: /home/hdg/Documents/freertos_thejas32/Source/portable/GCC/RISC-V/latest_files/portASM.S FreeRTOS_Source/portable/GCC/RISC-V/latest_files/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -x assembler-with-cpp -I"/home/hdg/Documents/freertos_thejas32/Source/portable/GCC/RISC-V/chip_specific_extensions/VEGA-THEJA32-ARIES" -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


