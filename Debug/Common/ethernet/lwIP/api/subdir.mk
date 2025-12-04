################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/hdg/my_application/Common/ethernet/lwIP/api/api_lib.c \
/home/hdg/my_application/Common/ethernet/lwIP/api/api_msg.c \
/home/hdg/my_application/Common/ethernet/lwIP/api/err.c \
/home/hdg/my_application/Common/ethernet/lwIP/api/sockets.c \
/home/hdg/my_application/Common/ethernet/lwIP/api/tcpip.c 

OBJS += \
./Common/ethernet/lwIP/api/api_lib.o \
./Common/ethernet/lwIP/api/api_msg.o \
./Common/ethernet/lwIP/api/err.o \
./Common/ethernet/lwIP/api/sockets.o \
./Common/ethernet/lwIP/api/tcpip.o 

C_DEPS += \
./Common/ethernet/lwIP/api/api_lib.d \
./Common/ethernet/lwIP/api/api_msg.d \
./Common/ethernet/lwIP/api/err.d \
./Common/ethernet/lwIP/api/sockets.d \
./Common/ethernet/lwIP/api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
Common/ethernet/lwIP/api/api_lib.o: /home/hdg/my_application/Common/ethernet/lwIP/api/api_lib.c Common/ethernet/lwIP/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/api/api_msg.o: /home/hdg/my_application/Common/ethernet/lwIP/api/api_msg.c Common/ethernet/lwIP/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/api/err.o: /home/hdg/my_application/Common/ethernet/lwIP/api/err.c Common/ethernet/lwIP/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/api/sockets.o: /home/hdg/my_application/Common/ethernet/lwIP/api/sockets.c Common/ethernet/lwIP/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/api/tcpip.o: /home/hdg/my_application/Common/ethernet/lwIP/api/tcpip.c Common/ethernet/lwIP/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


