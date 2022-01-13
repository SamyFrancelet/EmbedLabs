################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/work/EmbedLabs/RealtimeOscilloscope/ide-touchgfx-gen/Drivers/Components/ft5336/ft5336.c 

C_DEPS += \
./TouchGFX/Drivers/Components/ft5336/ft5336.d 

OBJS += \
./TouchGFX/Drivers/Components/ft5336/ft5336.o 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/Drivers/Components/ft5336/ft5336.o: C:/work/EmbedLabs/RealtimeOscilloscope/ide-touchgfx-gen/Drivers/Components/ft5336/ft5336.c TouchGFX/Drivers/Components/ft5336/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../ide-touchgfx-gen/TouchGFX/App" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../ide-touchgfx-gen/Drivers/Components" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/mdw" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/xf/include" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/xf/port" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/xf/port/default-cmsis-os" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/config" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

