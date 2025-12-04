################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_source/croutine.c \
../FreeRTOS_source/event_groups.c \
../FreeRTOS_source/list.c \
../FreeRTOS_source/queue.c \
../FreeRTOS_source/stream_buffer.c \
../FreeRTOS_source/tasks.c \
../FreeRTOS_source/timers.c 

OBJS += \
./FreeRTOS_source/croutine.o \
./FreeRTOS_source/event_groups.o \
./FreeRTOS_source/list.o \
./FreeRTOS_source/queue.o \
./FreeRTOS_source/stream_buffer.o \
./FreeRTOS_source/tasks.o \
./FreeRTOS_source/timers.o 

C_DEPS += \
./FreeRTOS_source/croutine.d \
./FreeRTOS_source/event_groups.d \
./FreeRTOS_source/list.d \
./FreeRTOS_source/queue.d \
./FreeRTOS_source/stream_buffer.d \
./FreeRTOS_source/tasks.d \
./FreeRTOS_source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_source/%.o: ../FreeRTOS_source/%.c FreeRTOS_source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_source/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_source/portable/GCC/RISC-V" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


