################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Source/portable/GCC/RISC-V/port.c 

S_UPPER_SRCS += \
../FreeRTOS_Source/portable/GCC/RISC-V/portASM.S 

OBJS += \
./FreeRTOS_Source/portable/GCC/RISC-V/port.o \
./FreeRTOS_Source/portable/GCC/RISC-V/portASM.o 

S_UPPER_DEPS += \
./FreeRTOS_Source/portable/GCC/RISC-V/portASM.d 

C_DEPS += \
./FreeRTOS_Source/portable/GCC/RISC-V/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Source/portable/GCC/RISC-V/%.o: ../FreeRTOS_Source/portable/GCC/RISC-V/%.c FreeRTOS_Source/portable/GCC/RISC-V/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/Demo/Common/include" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/Demo/RISCV_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/Demo/RISCV_CDAC_THEJAS32" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/FreeRTOS_Source/include" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/thejas32_hal/drivers/vega-sdk_freertos_thejas32/bsp" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/thejas32_hal/drivers/vega-sdk_freertos_thejas32/bsp/include" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/FreeRTOS_Source/portable/GCC/RISC-V" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/thejas32_hal/drivers/CoreUART" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/thejas32_hal/riscv_hal" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/thejas32_hal/hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

FreeRTOS_Source/portable/GCC/RISC-V/%.o: ../FreeRTOS_Source/portable/GCC/RISC-V/%.S FreeRTOS_Source/portable/GCC/RISC-V/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -x assembler-with-cpp -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/FreeRTOS_Source/portable/GCC/RISC-V/chip_specific_extensions/VEGA-THEJA32-ARIES" -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


