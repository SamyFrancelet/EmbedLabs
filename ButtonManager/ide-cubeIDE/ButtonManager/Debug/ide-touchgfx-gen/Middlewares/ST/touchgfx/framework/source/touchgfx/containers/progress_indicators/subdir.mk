################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/AbstractDirectionProgress.cpp \
D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/AbstractProgressIndicator.cpp \
D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/BoxProgress.cpp \
D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/CircleProgress.cpp \
D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/ImageProgress.cpp \
D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/LineProgress.cpp \
D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/TextProgress.cpp 

OBJS += \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/AbstractDirectionProgress.o \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/AbstractProgressIndicator.o \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/BoxProgress.o \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/CircleProgress.o \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/ImageProgress.o \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/LineProgress.o \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/TextProgress.o 

CPP_DEPS += \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/AbstractDirectionProgress.d \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/AbstractProgressIndicator.d \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/BoxProgress.d \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/CircleProgress.d \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/ImageProgress.d \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/LineProgress.d \
./ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/TextProgress.d 


# Each subdirectory must supply rules for building sources it contributes
ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/AbstractDirectionProgress.o: D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/AbstractDirectionProgress.cpp ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/default-idf" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/mdw" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Drivers/Components/ft5336" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/texts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/fonts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/gui/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/gui_generated/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/images/include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/AbstractProgressIndicator.o: D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/AbstractProgressIndicator.cpp ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/default-idf" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/mdw" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Drivers/Components/ft5336" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/texts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/fonts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/gui/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/gui_generated/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/images/include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/BoxProgress.o: D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/BoxProgress.cpp ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/default-idf" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/mdw" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Drivers/Components/ft5336" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/texts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/fonts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/gui/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/gui_generated/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/images/include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/CircleProgress.o: D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/CircleProgress.cpp ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/default-idf" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/mdw" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Drivers/Components/ft5336" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/texts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/fonts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/gui/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/gui_generated/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/images/include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/ImageProgress.o: D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/ImageProgress.cpp ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/default-idf" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/mdw" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Drivers/Components/ft5336" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/texts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/fonts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/gui/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/gui_generated/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/images/include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/LineProgress.o: D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/LineProgress.cpp ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/default-idf" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/mdw" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Drivers/Components/ft5336" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/texts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/fonts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/gui/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/gui_generated/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/images/include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/TextProgress.o: D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/TextProgress.cpp ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/source/touchgfx/containers/progress_indicators/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/default-idf" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/mdw" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Drivers/Components/ft5336" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/texts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/fonts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/gui/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/gui_generated/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/images/include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

