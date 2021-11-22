################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32f7xx_hal_msp.c \
../Core/Src/stm32f7xx_it.c \
../Core/Src/system_stm32f7xx.c 

CPP_SRCS += \
../Core/Src/isrs.cpp 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32f7xx_hal_msp.d \
./Core/Src/stm32f7xx_it.d \
./Core/Src/system_stm32f7xx.d 

OBJS += \
./Core/Src/isrs.o \
./Core/Src/main.o \
./Core/Src/stm32f7xx_hal_msp.o \
./Core/Src/stm32f7xx_it.o \
./Core/Src/system_stm32f7xx.o 

CPP_DEPS += \
./Core/Src/isrs.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/default-idf" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/mdw" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Drivers/Components/ft5336" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/texts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/fonts/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/gui/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/gui_generated/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/generated/images/include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"D:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"D:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/App" -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

