################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/AbortDelay.c \
/home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/EventGroupsDemo.c \
/home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/GenQTest.c \
/home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/TaskNotify.c \
/home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/TimerDemo.c \
/home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/blocktim.c \
/home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/countsem.c \
/home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/death.c \
/home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/dynamic.c \
/home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/recmutex.c 

OBJS += \
./full_demo/common_demo_tasks/AbortDelay.o \
./full_demo/common_demo_tasks/EventGroupsDemo.o \
./full_demo/common_demo_tasks/GenQTest.o \
./full_demo/common_demo_tasks/TaskNotify.o \
./full_demo/common_demo_tasks/TimerDemo.o \
./full_demo/common_demo_tasks/blocktim.o \
./full_demo/common_demo_tasks/countsem.o \
./full_demo/common_demo_tasks/death.o \
./full_demo/common_demo_tasks/dynamic.o \
./full_demo/common_demo_tasks/recmutex.o 

C_DEPS += \
./full_demo/common_demo_tasks/AbortDelay.d \
./full_demo/common_demo_tasks/EventGroupsDemo.d \
./full_demo/common_demo_tasks/GenQTest.d \
./full_demo/common_demo_tasks/TaskNotify.d \
./full_demo/common_demo_tasks/TimerDemo.d \
./full_demo/common_demo_tasks/blocktim.d \
./full_demo/common_demo_tasks/countsem.d \
./full_demo/common_demo_tasks/death.d \
./full_demo/common_demo_tasks/dynamic.d \
./full_demo/common_demo_tasks/recmutex.d 


# Each subdirectory must supply rules for building sources it contributes
full_demo/common_demo_tasks/AbortDelay.o: /home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/AbortDelay.c full_demo/common_demo_tasks/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/FreeRTOS/Demo/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

full_demo/common_demo_tasks/EventGroupsDemo.o: /home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/EventGroupsDemo.c full_demo/common_demo_tasks/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/FreeRTOS/Demo/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

full_demo/common_demo_tasks/GenQTest.o: /home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/GenQTest.c full_demo/common_demo_tasks/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/FreeRTOS/Demo/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

full_demo/common_demo_tasks/TaskNotify.o: /home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/TaskNotify.c full_demo/common_demo_tasks/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/FreeRTOS/Demo/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

full_demo/common_demo_tasks/TimerDemo.o: /home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/TimerDemo.c full_demo/common_demo_tasks/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/FreeRTOS/Demo/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

full_demo/common_demo_tasks/blocktim.o: /home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/blocktim.c full_demo/common_demo_tasks/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/FreeRTOS/Demo/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

full_demo/common_demo_tasks/countsem.o: /home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/countsem.c full_demo/common_demo_tasks/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/FreeRTOS/Demo/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

full_demo/common_demo_tasks/death.o: /home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/death.c full_demo/common_demo_tasks/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/FreeRTOS/Demo/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

full_demo/common_demo_tasks/dynamic.o: /home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/dynamic.c full_demo/common_demo_tasks/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/FreeRTOS/Demo/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

full_demo/common_demo_tasks/recmutex.o: /home/hdg/my_application/FreeRTOS/Demo/Common/Minimal/recmutex.c full_demo/common_demo_tasks/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-vega-elf-gcc -march=rv32im -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -O2 -fsigned-char -ffunction-sections -fdata-sections -g3 -DNOT_MSCC_STDIO_THRU_CORE_UART_APB -I"/home/hdg/my_application/Source/include" -I"/home/hdg/my_application/Source/portable/GCC/RISC-V" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/drivers/CoreUART" -I"/home/hdg/my_application/FreeRTOS/Demo/Common/include" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/hal" -I"/home/hdg/my_application/RISC-V_CDAC_THEJAS32/thejas32/riscv_hal" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


