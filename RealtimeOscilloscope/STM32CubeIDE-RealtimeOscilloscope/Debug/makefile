################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xf/port/stm32cube-cmsis-freertos/subdir.mk
-include xf/port/idf-stm32cube/subdir.mk
-include xf/port/idf-qt/subdir.mk
-include xf/port/default-qt/subdir.mk
-include xf/port/default-idf/subdir.mk
-include xf/port/default-cmsis-os/subdir.mk
-include xf/port/default/subdir.mk
-include xf/port/active-qt/subdir.mk
-include xf/core/subdir.mk
-include platform/f7-disco-gcc/mcu/hal/subdir.mk
-include platform/f7-disco-gcc/mcu/critical/subdir.mk
-include platform/f7-disco-gcc/ext-26pin/subdir.mk
-include platform/f7-disco-gcc/board/subdir.mk
-include mdw/trace/examples/subdir.mk
-include mdw/ext-freqgen/subdir.mk
-include app/interface/subdir.mk
-include app/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := STM32CubeIDE-RealtimeOscilloscope
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32CubeIDE-RealtimeOscilloscope.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32CubeIDE-RealtimeOscilloscope.list \

OBJCOPY_BIN += \
STM32CubeIDE-RealtimeOscilloscope.bin \


# All Target
all: main-build

# Main-build Target
main-build: STM32CubeIDE-RealtimeOscilloscope.elf secondary-outputs

# Tool invocations
STM32CubeIDE-RealtimeOscilloscope.elf: $(OBJS) $(USER_OBJS) C:\work\EmbedLabs\RealtimeOscilloscope\STM32CubeIDE-RealtimeOscilloscope\STM32F746NGHX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "STM32CubeIDE-RealtimeOscilloscope.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\work\EmbedLabs\RealtimeOscilloscope\STM32CubeIDE-RealtimeOscilloscope\STM32F746NGHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32CubeIDE-RealtimeOscilloscope.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32CubeIDE-RealtimeOscilloscope.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32CubeIDE-RealtimeOscilloscope.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32CubeIDE-RealtimeOscilloscope.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32CubeIDE-RealtimeOscilloscope.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJDUMP_LIST)$(C_UPPER_DEPS)$(S_DEPS)$(C_DEPS)$(OBJCOPY_BIN)$(CC_DEPS)$(SIZE_OUTPUT)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(CXX_DEPS)$(S_UPPER_DEPS)$(CPP_DEPS) STM32CubeIDE-RealtimeOscilloscope.elf
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
