################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/work/EmbedLabs/ButtonManager/src/mdw/button/buttoneventshandler.cpp \
C:/work/EmbedLabs/ButtonManager/src/mdw/button/buttonstatesm.cpp 

OBJS += \
./mdw/button/buttoneventshandler.o \
./mdw/button/buttonstatesm.o 

CPP_DEPS += \
./mdw/button/buttoneventshandler.d \
./mdw/button/buttonstatesm.d 


# Each subdirectory must supply rules for building sources it contributes
mdw/button/buttoneventshandler.o: C:/work/EmbedLabs/ButtonManager/src/mdw/button/buttoneventshandler.cpp mdw/button/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/default-idf" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/mdw" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Drivers/Components/ft5336" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/texts/include" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/fonts/include" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/gui/include" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/gui_generated/include" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/images/include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
mdw/button/buttonstatesm.o: C:/work/EmbedLabs/ButtonManager/src/mdw/button/buttonstatesm.cpp mdw/button/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/default-idf" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/mdw" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Drivers/Components/ft5336" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/texts/include" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/fonts/include" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/gui/include" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/gui_generated/include" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/images/include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
