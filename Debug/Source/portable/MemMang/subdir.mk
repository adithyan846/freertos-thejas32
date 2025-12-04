################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/portable/MemMang/heap_1.c \
../Source/portable/MemMang/heap_2.c \
../Source/portable/MemMang/heap_3.c \
../Source/portable/MemMang/heap_4.c \
../Source/portable/MemMang/heap_5.c 

OBJS += \
./Source/portable/MemMang/heap_1.o \
./Source/portable/MemMang/heap_2.o \
./Source/portable/MemMang/heap_3.o \
./Source/portable/MemMang/heap_4.o \
./Source/portable/MemMang/heap_5.o 

C_DEPS += \
./Source/portable/MemMang/heap_1.d \
./Source/portable/MemMang/heap_2.d \
./Source/portable/MemMang/heap_3.d \
./Source/portable/MemMang/heap_4.d \
./Source/portable/MemMang/heap_5.d 


# Each subdirectory must supply rules for building sources it contributes
Source/portable/MemMang/%.o: ../Source/portable/MemMang/%.c Source/portable/MemMang/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/Source/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/Source/portable/GCC/RISC-V" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


