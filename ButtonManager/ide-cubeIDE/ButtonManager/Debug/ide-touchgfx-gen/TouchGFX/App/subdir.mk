################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/App/app_touchgfx.c 

C_DEPS += \
./ide-touchgfx-gen/TouchGFX/App/app_touchgfx.d 

OBJS += \
./ide-touchgfx-gen/TouchGFX/App/app_touchgfx.o 


# Each subdirectory must supply rules for building sources it contributes
ide-touchgfx-gen/TouchGFX/App/app_touchgfx.o: C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/App/app_touchgfx.c ide-touchgfx-gen/TouchGFX/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/Core/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/include" -I"C:/work/EmbedLabs/ButtonManager/ide-cubeIDE/ButtonManager/../../src/xf/port/" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/target/generated" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/Middlewares/ST/touchgfx/framework/include" -I"C:/work/EmbedLabs/ButtonManager/ide-touchgfx-gen/TouchGFX/App" -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

