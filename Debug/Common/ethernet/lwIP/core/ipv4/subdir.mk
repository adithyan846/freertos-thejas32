################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/hdg/my_application/Common/ethernet/lwIP/core/ipv4/icmp.c \
/home/hdg/my_application/Common/ethernet/lwIP/core/ipv4/ip.c \
/home/hdg/my_application/Common/ethernet/lwIP/core/ipv4/ip_addr.c \
/home/hdg/my_application/Common/ethernet/lwIP/core/ipv4/ip_frag.c 

OBJS += \
./Common/ethernet/lwIP/core/ipv4/icmp.o \
./Common/ethernet/lwIP/core/ipv4/ip.o \
./Common/ethernet/lwIP/core/ipv4/ip_addr.o \
./Common/ethernet/lwIP/core/ipv4/ip_frag.o 

C_DEPS += \
./Common/ethernet/lwIP/core/ipv4/icmp.d \
./Common/ethernet/lwIP/core/ipv4/ip.d \
./Common/ethernet/lwIP/core/ipv4/ip_addr.d \
./Common/ethernet/lwIP/core/ipv4/ip_frag.d 


# Each subdirectory must supply rules for building sources it contributes
Common/ethernet/lwIP/core/ipv4/icmp.o: /home/hdg/my_application/Common/ethernet/lwIP/core/ipv4/icmp.c Common/ethernet/lwIP/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/core/ipv4/ip.o: /home/hdg/my_application/Common/ethernet/lwIP/core/ipv4/ip.c Common/ethernet/lwIP/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/core/ipv4/ip_addr.o: /home/hdg/my_application/Common/ethernet/lwIP/core/ipv4/ip_addr.c Common/ethernet/lwIP/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/core/ipv4/ip_frag.o: /home/hdg/my_application/Common/ethernet/lwIP/core/ipv4/ip_frag.c Common/ethernet/lwIP/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


