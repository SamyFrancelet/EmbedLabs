################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xf/port/idf-stm32cube/subdir.mk
-include xf/port/default-idf/subdir.mk
-include xf/port/default/subdir.mk
-include xf/core/subdir.mk
-include startup/subdir.mk
-include platform/f7-disco-gcc/mcu/hal/subdir.mk
-include platform/f7-disco-gcc/mcu/critical/subdir.mk
-include platform/f7-disco-gcc/ext-26pin/subdir.mk
-include platform/f7-disco-gcc/board/subdir.mk
-include mdw/trace/examples/subdir.mk
-include ide-touchgfx-gen/TouchGFX/target/generated/subdir.mk
-include ide-touchgfx-gen/TouchGFX/target/subdir.mk
-include ide-touchgfx-gen/TouchGFX/gui/src/terminal_screen/subdir.mk
-include ide-touchgfx-gen/TouchGFX/gui/src/model/subdir.mk
-include ide-touchgfx-gen/TouchGFX/gui/src/common/subdir.mk
-include ide-touchgfx-gen/TouchGFX/generated/texts/src/subdir.mk
-include ide-touchgfx-gen/TouchGFX/generated/images/src/__designer/subdir.mk
-include ide-touchgfx-gen/TouchGFX/generated/images/src/subdir.mk
-include ide-touchgfx-gen/TouchGFX/generated/gui_generated/src/terminal_screen/subdir.mk
-include ide-touchgfx-gen/TouchGFX/generated/gui_generated/src/common/subdir.mk
-include ide-touchgfx-gen/TouchGFX/generated/fonts/src/subdir.mk
-include ide-touchgfx-gen/TouchGFX/App/subdir.mk
-include ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/graph/subdir.mk
-include ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/canvas/subdir.mk
-include ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/widgets/subdir.mk
-include ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/scrollers/subdir.mk
-include ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/subdir.mk
-include ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/clock/subdir.mk
-include ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/subdir.mk
-include ide-touchgfx-gen/Drivers/Components/ft5336/subdir.mk
-include event/subdir.mk
-include app/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
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


BUILD_ARTIFACT_NAME := ButtonManager
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ButtonManager.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ButtonManager.list \

OBJCOPY_BIN += \
ButtonManager.bin \


# All Target
all: main-build

# Main-build Target
main-build: ButtonManager.elf secondary-outputs

# Tool invocations
ButtonManager.elf: $(OBJS) $(USER_OBJS) ../STM32F746NGHx_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "ButtonManager.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"../STM32F746NGHx_FLASH.ld" --specs=nosys.specs -Wl,-Map="ButtonManager.map" -Wl,--gc-sections -static -L"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../ide-touchgfx-gen/Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ButtonManager.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ButtonManager.list"
	@echo 'Finished building: $@'
	@echo ' '

ButtonManager.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ButtonManager.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJDUMP_LIST)$(C_UPPER_DEPS)$(S_DEPS)$(C_DEPS)$(OBJCOPY_BIN)$(CC_DEPS)$(SIZE_OUTPUT)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(CXX_DEPS)$(S_UPPER_DEPS)$(CPP_DEPS) ButtonManager.elf
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
