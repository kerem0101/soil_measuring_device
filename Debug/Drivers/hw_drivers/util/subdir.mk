################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/hw_drivers/util/DWT_Delay.c 

OBJS += \
./Drivers/hw_drivers/util/DWT_Delay.o 

C_DEPS += \
./Drivers/hw_drivers/util/DWT_Delay.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/hw_drivers/util/%.o Drivers/hw_drivers/util/%.su: ../Drivers/hw_drivers/util/%.c Drivers/hw_drivers/util/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-hw_drivers-2f-util

clean-Drivers-2f-hw_drivers-2f-util:
	-$(RM) ./Drivers/hw_drivers/util/DWT_Delay.d ./Drivers/hw_drivers/util/DWT_Delay.o ./Drivers/hw_drivers/util/DWT_Delay.su

.PHONY: clean-Drivers-2f-hw_drivers-2f-util

