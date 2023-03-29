################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Modules/Adafruit_GFX/Src/Adafruit_GFX.cpp \
../Modules/Adafruit_GFX/Src/Draw_Write.cpp \
../Modules/Adafruit_GFX/Src/ILI9341.cpp \
../Modules/Adafruit_GFX/Src/delay_us.cpp 

OBJS += \
./Modules/Adafruit_GFX/Src/Adafruit_GFX.o \
./Modules/Adafruit_GFX/Src/Draw_Write.o \
./Modules/Adafruit_GFX/Src/ILI9341.o \
./Modules/Adafruit_GFX/Src/delay_us.o 

CPP_DEPS += \
./Modules/Adafruit_GFX/Src/Adafruit_GFX.d \
./Modules/Adafruit_GFX/Src/Draw_Write.d \
./Modules/Adafruit_GFX/Src/ILI9341.d \
./Modules/Adafruit_GFX/Src/delay_us.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/Adafruit_GFX/Src/%.o Modules/Adafruit_GFX/Src/%.su: ../Modules/Adafruit_GFX/Src/%.cpp Modules/Adafruit_GFX/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Modules/Snake/Inc/ -I../Modules/Process/Inc/ -I../Modules/Tetris/Inc/ -I../Modules/Buttons/Inc/ -I../Modules/Adafruit_GFX/Inc/ -I../Modules/Adafruit_GFX/Fonts -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modules-2f-Adafruit_GFX-2f-Src

clean-Modules-2f-Adafruit_GFX-2f-Src:
	-$(RM) ./Modules/Adafruit_GFX/Src/Adafruit_GFX.d ./Modules/Adafruit_GFX/Src/Adafruit_GFX.o ./Modules/Adafruit_GFX/Src/Adafruit_GFX.su ./Modules/Adafruit_GFX/Src/Draw_Write.d ./Modules/Adafruit_GFX/Src/Draw_Write.o ./Modules/Adafruit_GFX/Src/Draw_Write.su ./Modules/Adafruit_GFX/Src/ILI9341.d ./Modules/Adafruit_GFX/Src/ILI9341.o ./Modules/Adafruit_GFX/Src/ILI9341.su ./Modules/Adafruit_GFX/Src/delay_us.d ./Modules/Adafruit_GFX/Src/delay_us.o ./Modules/Adafruit_GFX/Src/delay_us.su

.PHONY: clean-Modules-2f-Adafruit_GFX-2f-Src

