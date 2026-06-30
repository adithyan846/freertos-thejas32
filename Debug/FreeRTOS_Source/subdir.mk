################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Source/croutine.c \
../FreeRTOS_Source/event_groups.c \
../FreeRTOS_Source/list.c \
../FreeRTOS_Source/queue.c \
../FreeRTOS_Source/stream_buffer.c \
../FreeRTOS_Source/tasks.c \
../FreeRTOS_Source/timers.c 

OBJS += \
./FreeRTOS_Source/croutine.o \
./FreeRTOS_Source/event_groups.o \
./FreeRTOS_Source/list.o \
./FreeRTOS_Source/queue.o \
./FreeRTOS_Source/stream_buffer.o \
./FreeRTOS_Source/tasks.o \
./FreeRTOS_Source/timers.o 

C_DEPS += \
./FreeRTOS_Source/croutine.d \
./FreeRTOS_Source/event_groups.d \
./FreeRTOS_Source/list.d \
./FreeRTOS_Source/queue.d \
./FreeRTOS_Source/stream_buffer.d \
./FreeRTOS_Source/tasks.d \
./FreeRTOS_Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Source/%.o: ../FreeRTOS_Source/%.c FreeRTOS_Source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/Demo/Common/include" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/Demo/RISCV_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/Demo/RISCV_CDAC_THEJAS32" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/FreeRTOS_Source/include" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/thejas32_hal/drivers/vega-sdk_freertos_thejas32/bsp" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/thejas32_hal/drivers/vega-sdk_freertos_thejas32/bsp/include" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/FreeRTOS_Source/portable/GCC/RISC-V" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/thejas32_hal/drivers/CoreUART" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/thejas32_hal/riscv_hal" -I"/home/saurav/Documents/Freertos_thejas32_main/freertos-thejas32/thejas32_hal/hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


