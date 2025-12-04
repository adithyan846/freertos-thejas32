################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/api_lib.c \
/home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/api_msg.c \
/home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/err.c \
/home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/netbuf.c \
/home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/netdb.c \
/home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/netifapi.c \
/home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/sockets.c \
/home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/tcpip.c 

OBJS += \
./Common/ethernet/lwip-1.4.0/src/api/api_lib.o \
./Common/ethernet/lwip-1.4.0/src/api/api_msg.o \
./Common/ethernet/lwip-1.4.0/src/api/err.o \
./Common/ethernet/lwip-1.4.0/src/api/netbuf.o \
./Common/ethernet/lwip-1.4.0/src/api/netdb.o \
./Common/ethernet/lwip-1.4.0/src/api/netifapi.o \
./Common/ethernet/lwip-1.4.0/src/api/sockets.o \
./Common/ethernet/lwip-1.4.0/src/api/tcpip.o 

C_DEPS += \
./Common/ethernet/lwip-1.4.0/src/api/api_lib.d \
./Common/ethernet/lwip-1.4.0/src/api/api_msg.d \
./Common/ethernet/lwip-1.4.0/src/api/err.d \
./Common/ethernet/lwip-1.4.0/src/api/netbuf.d \
./Common/ethernet/lwip-1.4.0/src/api/netdb.d \
./Common/ethernet/lwip-1.4.0/src/api/netifapi.d \
./Common/ethernet/lwip-1.4.0/src/api/sockets.d \
./Common/ethernet/lwip-1.4.0/src/api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
Common/ethernet/lwip-1.4.0/src/api/api_lib.o: /home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/api_lib.c Common/ethernet/lwip-1.4.0/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwip-1.4.0/src/api/api_msg.o: /home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/api_msg.c Common/ethernet/lwip-1.4.0/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwip-1.4.0/src/api/err.o: /home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/err.c Common/ethernet/lwip-1.4.0/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwip-1.4.0/src/api/netbuf.o: /home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/netbuf.c Common/ethernet/lwip-1.4.0/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwip-1.4.0/src/api/netdb.o: /home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/netdb.c Common/ethernet/lwip-1.4.0/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwip-1.4.0/src/api/netifapi.o: /home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/netifapi.c Common/ethernet/lwip-1.4.0/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwip-1.4.0/src/api/sockets.o: /home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/sockets.c Common/ethernet/lwip-1.4.0/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwip-1.4.0/src/api/tcpip.o: /home/hdg/my_application/Common/ethernet/lwip-1.4.0/src/api/tcpip.c Common/ethernet/lwip-1.4.0/src/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


