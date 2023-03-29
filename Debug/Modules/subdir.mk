################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Modules/Adafruit_GFX.cpp \
../Modules/Draw_Write.cpp \
../Modules/ILI9341.cpp \
../Modules/delay_us.cpp \
../Modules/glcdfont.cpp 

OBJS += \
./Modules/Adafruit_GFX.o \
./Modules/Draw_Write.o \
./Modules/ILI9341.o \
./Modules/delay_us.o \
./Modules/glcdfont.o 

CPP_DEPS += \
./Modules/Adafruit_GFX.d \
./Modules/Draw_Write.d \
./Modules/ILI9341.d \
./Modules/delay_us.d \
./Modules/glcdfont.d 


# Each subdirectory must supply rules for building sources it contributes
Modules/%.o Modules/%.su: ../Modules/%.cpp Modules/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Modules/ -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Modules

clean-Modules:
	-$(RM) ./Modules/Adafruit_GFX.d ./Modules/Adafruit_GFX.o ./Modules/Adafruit_GFX.su ./Modules/Draw_Write.d ./Modules/Draw_Write.o ./Modules/Draw_Write.su ./Modules/ILI9341.d ./Modules/ILI9341.o ./Modules/ILI9341.su ./Modules/delay_us.d ./Modules/delay_us.o ./Modules/delay_us.su ./Modules/glcdfont.d ./Modules/glcdfont.o ./Modules/glcdfont.su

.PHONY: clean-Modules

