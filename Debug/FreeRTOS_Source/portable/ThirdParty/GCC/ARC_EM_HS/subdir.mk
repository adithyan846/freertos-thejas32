################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/arc_freertos_exceptions.c \
../FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/freertos_tls.c \
../FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/port.c 

OBJS += \
./FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/arc_freertos_exceptions.o \
./FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/freertos_tls.o \
./FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/port.o 

C_DEPS += \
./FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/arc_freertos_exceptions.d \
./FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/freertos_tls.d \
./FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/%.o: ../FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/%.c FreeRTOS_Source/portable/ThirdParty/GCC/ARC_EM_HS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_Source/include" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/FreeRTOS_Source/portable/GCC/RISC-V" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -I"/home/hdg/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/Common/include" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


