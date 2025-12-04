################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_source/portable/GCC/RISC-V/port.c 

S_UPPER_SRCS += \
../FreeRTOS_source/portable/GCC/RISC-V/portASM.S 

OBJS += \
./FreeRTOS_source/portable/GCC/RISC-V/port.o \
./FreeRTOS_source/portable/GCC/RISC-V/portASM.o 

S_UPPER_DEPS += \
./FreeRTOS_source/portable/GCC/RISC-V/portASM.d 

C_DEPS += \
./FreeRTOS_source/portable/GCC/RISC-V/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_source/portable/GCC/RISC-V/%.o: ../FreeRTOS_source/portable/GCC/RISC-V/%.c FreeRTOS_source/portable/GCC/RISC-V/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_source/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_source/portable/GCC/RISC-V" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS_source/portable/GCC/RISC-V/%.o: ../FreeRTOS_source/portable/GCC/RISC-V/%.S FreeRTOS_source/portable/GCC/RISC-V/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -x assembler-with-cpp -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


