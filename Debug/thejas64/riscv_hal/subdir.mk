################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../thejas64/riscv_hal/init.c \
../thejas64/riscv_hal/riscv_hal.c \
../thejas64/riscv_hal/riscv_hal_stubs.c \
../thejas64/riscv_hal/syscall.c 

S_UPPER_SRCS += \
../thejas64/riscv_hal/entry.S 

OBJS += \
./thejas64/riscv_hal/entry.o \
./thejas64/riscv_hal/init.o \
./thejas64/riscv_hal/riscv_hal.o \
./thejas64/riscv_hal/riscv_hal_stubs.o \
./thejas64/riscv_hal/syscall.o 

S_UPPER_DEPS += \
./thejas64/riscv_hal/entry.d 

C_DEPS += \
./thejas64/riscv_hal/init.d \
./thejas64/riscv_hal/riscv_hal.d \
./thejas64/riscv_hal/riscv_hal_stubs.d \
./thejas64/riscv_hal/syscall.d 


# Each subdirectory must supply rules for building sources it contributes
thejas64/riscv_hal/%.o: ../thejas64/riscv_hal/%.S thejas64/riscv_hal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O0 -fsigned-char -ffunction-sections -fdata-sections -g3 -x assembler-with-cpp -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Source/portable/GCC/RISC-V/chip_specific_extensions/VEGA-THEJA32-ARIES" -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

thejas64/riscv_hal/%.o: ../thejas64/riscv_hal/%.c thejas64/riscv_hal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O0 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Source/include" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Source/portable/GCC/RISC-V" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32/thejas64/drivers/vega-sdk/bsp/include" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32/thejas64/drivers/CoreUART" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/Common/include" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32/thejas64/hal" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32/thejas64/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


