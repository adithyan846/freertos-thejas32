################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../thejas32/hal/hal_irq.c 

S_UPPER_SRCS += \
../thejas32/hal/hw_reg_access.S 

OBJS += \
./thejas32/hal/hal_irq.o \
./thejas32/hal/hw_reg_access.o 

S_UPPER_DEPS += \
./thejas32/hal/hw_reg_access.d 

C_DEPS += \
./thejas32/hal/hal_irq.d 


# Each subdirectory must supply rules for building sources it contributes
thejas32/hal/%.o: ../thejas32/hal/%.c thejas32/hal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32" -I"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_Source/include" -I"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_Source/portable/GCC/RISC-V" -I"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -I"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/Common/include" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

thejas32/hal/%.o: ../thejas32/hal/%.S thejas32/hal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -x assembler-with-cpp -I"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_Source/portable/GCC/RISC-V/chip_specific_extensions/VEGA-THEJA32-ARIES" -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


