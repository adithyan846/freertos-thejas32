################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/ads1015.c \
../thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/i2c_api.c \
../thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/pulse_sensor_demo.c 

OBJS += \
./thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/ads1015.o \
./thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/i2c_api.o \
./thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/pulse_sensor_demo.o 

C_DEPS += \
./thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/ads1015.d \
./thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/i2c_api.d \
./thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/pulse_sensor_demo.d 


# Each subdirectory must supply rules for building sources it contributes
thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/%.o: ../thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/%.c thejas32/drivers/vega-sdk/examples/adc/pulse_sensor_demo/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Source/include" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Source/portable/GCC/RISC-V" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/Common/include" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/Documents/saurav/freertos_latest/freertos/FreeRTOS/Demo/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


