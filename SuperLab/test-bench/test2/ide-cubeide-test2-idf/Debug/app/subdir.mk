################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/work/EmbedLabs/SuperLab/test-bench/test2/src/app/statemachine02.cpp \
C:/work/EmbedLabs/SuperLab/test-bench/test2/src/app/testfactory02.cpp 

OBJS += \
./app/statemachine02.o \
./app/testfactory02.o 

CPP_DEPS += \
./app/statemachine02.d \
./app/testfactory02.d 


# Each subdirectory must supply rules for building sources it contributes
app/statemachine02.o: C:/work/EmbedLabs/SuperLab/test-bench/test2/src/app/statemachine02.cpp app/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/../src" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/Core/Inc" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf" -I"C:/work/EmbedLabs/SuperLab/src/platform/f7-disco-gcc" -I"C:/work/EmbedLabs/SuperLab/src/platform/f7-disco-gcc/mcu" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/../../../src" -I"C:/work/EmbedLabs/SuperLab/src/simplified/xf/include" -I"C:/work/EmbedLabs/SuperLab/src/simplified/xf/port" -I"C:/work/EmbedLabs/SuperLab/src/simplified/xf/port/common" -I"C:/work/EmbedLabs/SuperLab/src/simplified/xf/port/idf-stm32" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/../../../src/mdw" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/../../../src/mdw/trace" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/../../common" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/Drivers/CMSIS/Include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
app/testfactory02.o: C:/work/EmbedLabs/SuperLab/test-bench/test2/src/app/testfactory02.cpp app/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/../src" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/Core/Inc" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf" -I"C:/work/EmbedLabs/SuperLab/src/platform/f7-disco-gcc" -I"C:/work/EmbedLabs/SuperLab/src/platform/f7-disco-gcc/mcu" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/../../../src" -I"C:/work/EmbedLabs/SuperLab/src/simplified/xf/include" -I"C:/work/EmbedLabs/SuperLab/src/simplified/xf/port" -I"C:/work/EmbedLabs/SuperLab/src/simplified/xf/port/common" -I"C:/work/EmbedLabs/SuperLab/src/simplified/xf/port/idf-stm32" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/../../../src/mdw" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/../../../src/mdw/trace" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/../../common" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/work/EmbedLabs/SuperLab/test-bench/test2/ide-cubeide-test2-idf/Drivers/CMSIS/Include" -Og -ffunction-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

