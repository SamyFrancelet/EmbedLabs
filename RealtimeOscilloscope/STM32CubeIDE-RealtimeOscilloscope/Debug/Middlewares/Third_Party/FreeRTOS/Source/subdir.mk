################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/croutine.c \
../Middlewares/Third_Party/FreeRTOS/Source/event_groups.c \
../Middlewares/Third_Party/FreeRTOS/Source/list.c \
../Middlewares/Third_Party/FreeRTOS/Source/queue.c \
../Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c \
../Middlewares/Third_Party/FreeRTOS/Source/tasks.c \
../Middlewares/Third_Party/FreeRTOS/Source/timers.c 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/croutine.d \
./Middlewares/Third_Party/FreeRTOS/Source/event_groups.d \
./Middlewares/Third_Party/FreeRTOS/Source/list.d \
./Middlewares/Third_Party/FreeRTOS/Source/queue.d \
./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d \
./Middlewares/Third_Party/FreeRTOS/Source/tasks.d \
./Middlewares/Third_Party/FreeRTOS/Source/timers.d 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/croutine.o \
./Middlewares/Third_Party/FreeRTOS/Source/event_groups.o \
./Middlewares/Third_Party/FreeRTOS/Source/list.o \
./Middlewares/Third_Party/FreeRTOS/Source/queue.o \
./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o \
./Middlewares/Third_Party/FreeRTOS/Source/tasks.o \
./Middlewares/Third_Party/FreeRTOS/Source/timers.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/%.c Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../ide-touchgfx-gen/TouchGFX/App" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../ide-touchgfx-gen/Drivers/Components" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/platform/f7-disco-gcc" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/platform/f7-disco-gcc/mcu" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/mdw" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/xf/include" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/xf/port" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/xf/port/default-idf" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/xf/port/default-cmsis-os" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src" -I"C:/work/EmbedLabs/RealtimeOscilloscope/STM32CubeIDE-RealtimeOscilloscope/../src/config" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

