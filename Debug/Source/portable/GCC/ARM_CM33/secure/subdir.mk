################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/portable/GCC/ARM_CM33/secure/secure_context.c \
../Source/portable/GCC/ARM_CM33/secure/secure_context_port.c \
../Source/portable/GCC/ARM_CM33/secure/secure_heap.c \
../Source/portable/GCC/ARM_CM33/secure/secure_init.c 

OBJS += \
./Source/portable/GCC/ARM_CM33/secure/secure_context.o \
./Source/portable/GCC/ARM_CM33/secure/secure_context_port.o \
./Source/portable/GCC/ARM_CM33/secure/secure_heap.o \
./Source/portable/GCC/ARM_CM33/secure/secure_init.o 

C_DEPS += \
./Source/portable/GCC/ARM_CM33/secure/secure_context.d \
./Source/portable/GCC/ARM_CM33/secure/secure_context_port.d \
./Source/portable/GCC/ARM_CM33/secure/secure_heap.d \
./Source/portable/GCC/ARM_CM33/secure/secure_init.d 


# Each subdirectory must supply rules for building sources it contributes
Source/portable/GCC/ARM_CM33/secure/%.o: ../Source/portable/GCC/ARM_CM33/secure/%.c Source/portable/GCC/ARM_CM33/secure/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/Source/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/Source/portable/GCC/RISC-V" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


