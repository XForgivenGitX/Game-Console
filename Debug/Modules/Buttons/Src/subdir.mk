################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Modules/Buttons/Src/but_controlBlock.cpp \
../Modules/Buttons/Src/but_detail.cpp 

OBJS += \
./Modules/Buttons/Src/but_controlBlock.o \
./Modules/Buttons/Src/but_detail.o 

CPP_DEPS += \
./Modules/Buttons/Src/but_controlBlock.d \
./Modules/Buttons/Src/but_detail.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/Buttons/Src/%.o Modules/Buttons/Src/%.su: ../Modules/Buttons/Src/%.cpp Modules/Buttons/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Modules/Snake/Inc/ -I../Modules/Process/Inc/ -I../Modules/Tetris/Inc/ -I../Modules/Buttons/Inc/ -I../Modules/Adafruit_GFX/Inc/ -I../Modules/Adafruit_GFX/Fonts -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modules-2f-Buttons-2f-Src

clean-Modules-2f-Buttons-2f-Src:
	-$(RM) ./Modules/Buttons/Src/but_controlBlock.d ./Modules/Buttons/Src/but_controlBlock.o ./Modules/Buttons/Src/but_controlBlock.su ./Modules/Buttons/Src/but_detail.d ./Modules/Buttons/Src/but_detail.o ./Modules/Buttons/Src/but_detail.su

.PHONY: clean-Modules-2f-Buttons-2f-Src

