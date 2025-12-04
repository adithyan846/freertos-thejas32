################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/auth.c \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/chap.c \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/chpms.c \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/fsm.c \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/ipcp.c \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/lcp.c \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/magic.c \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/md5.c \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/pap.c \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/ppp.c \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/randm.c \
/home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/vj.c 

OBJS += \
./Common/ethernet/lwIP/netif/ppp/auth.o \
./Common/ethernet/lwIP/netif/ppp/chap.o \
./Common/ethernet/lwIP/netif/ppp/chpms.o \
./Common/ethernet/lwIP/netif/ppp/fsm.o \
./Common/ethernet/lwIP/netif/ppp/ipcp.o \
./Common/ethernet/lwIP/netif/ppp/lcp.o \
./Common/ethernet/lwIP/netif/ppp/magic.o \
./Common/ethernet/lwIP/netif/ppp/md5.o \
./Common/ethernet/lwIP/netif/ppp/pap.o \
./Common/ethernet/lwIP/netif/ppp/ppp.o \
./Common/ethernet/lwIP/netif/ppp/randm.o \
./Common/ethernet/lwIP/netif/ppp/vj.o 

C_DEPS += \
./Common/ethernet/lwIP/netif/ppp/auth.d \
./Common/ethernet/lwIP/netif/ppp/chap.d \
./Common/ethernet/lwIP/netif/ppp/chpms.d \
./Common/ethernet/lwIP/netif/ppp/fsm.d \
./Common/ethernet/lwIP/netif/ppp/ipcp.d \
./Common/ethernet/lwIP/netif/ppp/lcp.d \
./Common/ethernet/lwIP/netif/ppp/magic.d \
./Common/ethernet/lwIP/netif/ppp/md5.d \
./Common/ethernet/lwIP/netif/ppp/pap.d \
./Common/ethernet/lwIP/netif/ppp/ppp.d \
./Common/ethernet/lwIP/netif/ppp/randm.d \
./Common/ethernet/lwIP/netif/ppp/vj.d 


# Each subdirectory must supply rules for building sources it contributes
Common/ethernet/lwIP/netif/ppp/auth.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/auth.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/netif/ppp/chap.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/chap.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/netif/ppp/chpms.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/chpms.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/netif/ppp/fsm.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/fsm.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/netif/ppp/ipcp.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/ipcp.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/netif/ppp/lcp.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/lcp.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/netif/ppp/magic.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/magic.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/netif/ppp/md5.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/md5.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/netif/ppp/pap.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/pap.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/netif/ppp/ppp.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/ppp.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/netif/ppp/randm.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/randm.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/ethernet/lwIP/netif/ppp/vj.o: /home/hdg/my_application/Common/ethernet/lwIP/netif/ppp/vj.c Common/ethernet/lwIP/netif/ppp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


