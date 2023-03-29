################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Modules/Tetris/Src/TetrisLogic.cpp \
../Modules/Tetris/Src/TetrisTask.cpp 

OBJS += \
./Modules/Tetris/Src/TetrisLogic.o \
./Modules/Tetris/Src/TetrisTask.o 

CPP_DEPS += \
./Modules/Tetris/Src/TetrisLogic.d \
./Modules/Tetris/Src/TetrisTask.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/Tetris/Src/%.o Modules/Tetris/Src/%.su: ../Modules/Tetris/Src/%.cpp Modules/Tetris/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Modules/Snake/Inc/ -I../Modules/Process/Inc/ -I../Modules/Tetris/Inc/ -I../Modules/Buttons/Inc/ -I../Modules/Adafruit_GFX/Inc/ -I../Modules/Adafruit_GFX/Fonts -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modules-2f-Tetris-2f-Src

clean-Modules-2f-Tetris-2f-Src:
	-$(RM) ./Modules/Tetris/Src/TetrisLogic.d ./Modules/Tetris/Src/TetrisLogic.o ./Modules/Tetris/Src/TetrisLogic.su ./Modules/Tetris/Src/TetrisTask.d ./Modules/Tetris/Src/TetrisTask.o ./Modules/Tetris/Src/TetrisTask.su

.PHONY: clean-Modules-2f-Tetris-2f-Src

