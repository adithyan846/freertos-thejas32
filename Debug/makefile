################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include thejas32/riscv_hal/subdir.mk
-include thejas32/hal/subdir.mk
-include thejas32/drivers/vega-sdk/bsp/drivers/uart/subdir.mk
-include thejas32/drivers/vega-sdk/bsp/drivers/timer/subdir.mk
-include thejas32/drivers/vega-sdk/bsp/drivers/spi/subdir.mk
-include thejas32/drivers/vega-sdk/bsp/drivers/qspi/subdir.mk
-include thejas32/drivers/vega-sdk/bsp/drivers/pwm/subdir.mk
-include thejas32/drivers/vega-sdk/bsp/drivers/interrupt/subdir.mk
-include thejas32/drivers/vega-sdk/bsp/drivers/i2c/subdir.mk
-include thejas32/drivers/vega-sdk/bsp/drivers/gpio/subdir.mk
-include thejas32/drivers/vega-sdk/bsp/drivers/at25sf161_flash/subdir.mk
-include thejas32/drivers/vega-sdk/bsp/common/subdir.mk
-include thejas32/drivers/CoreUART/subdir.mk
-include full_demo/subdir.mk
-include blinky_demo/subdir.mk
-include Libraryapp/subdir.mk
-include Initialization/subdir.mk
-include FreeRTOS_Source/portable/MemMang/subdir.mk
-include FreeRTOS_Source/portable/GCC/RISC-V/subdir.mk
-include FreeRTOS_Source/portable/Common/subdir.mk
-include FreeRTOS_Source/subdir.mk
-include Applications/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := RTOSDemo
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
RTOSDemo.bin \

SECONDARY_LIST += \
RTOSDemo.lst \

SECONDARY_SIZE += \
RTOSDemo.siz \


# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: RTOSDemo.elf secondary-outputs

# Tool invocations
RTOSDemo.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU RISC-V Cross C Linker'
	riscv32-vega-elf-gcc -march=rv32i -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -march=rv32i_zicsr -Og -fsigned-char -ffunction-sections -fdata-sections -g -g3 -T "/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/riscv-thejas32.ld" -nostartfiles -Xlinker --gc-sections -L"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/thejas32/drivers/vega-sdk/bsp" -L"/home/saurav/Downloads/freertos_itns_googledrive/RISC-V_CDAC_THEJAS32/full_demo/mq3_includes" -Wl,-Map,"RTOSDemo.map" -v -o "RTOSDemo.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

RTOSDemo.bin: RTOSDemo.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Create Flash Image'
	riscv32-vega-elf-objcopy -O binary --gap-fill 0 -I elf64-littleriscv  --set-section-flags .bss=alloc,load,contents --set-section-flags .sbss=alloc,load,contents "RTOSDemo.elf"  "RTOSDemo.bin"
	@echo 'Finished building: $@'
	@echo ' '

RTOSDemo.lst: RTOSDemo.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Create Listing'
	riscv32-vega-elf-objdump --source --all-headers --demangle --debugging --line-numbers --wide "RTOSDemo.elf" > "RTOSDemo.lst"
	@echo 'Finished building: $@'
	@echo ' '

RTOSDemo.siz: RTOSDemo.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Print Size'
	riscv32-vega-elf-size --format=berkeley "RTOSDemo.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SX_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) RTOSDemo.elf
	-@echo ' '

post-build:
	-riscv32-vega-elf-objdump -D RTOSDemo.elf  > RTOSDemo.dump
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
