################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/hw_drivers/bluetooth_drivers/bluetooth_driver.c 

OBJS += \
./Drivers/hw_drivers/bluetooth_drivers/bluetooth_driver.o 

C_DEPS += \
./Drivers/hw_drivers/bluetooth_drivers/bluetooth_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/hw_drivers/bluetooth_drivers/%.o Drivers/hw_drivers/bluetooth_drivers/%.su: ../Drivers/hw_drivers/bluetooth_drivers/%.c Drivers/hw_drivers/bluetooth_drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-hw_drivers-2f-bluetooth_drivers

clean-Drivers-2f-hw_drivers-2f-bluetooth_drivers:
	-$(RM) ./Drivers/hw_drivers/bluetooth_drivers/bluetooth_driver.d ./Drivers/hw_drivers/bluetooth_drivers/bluetooth_driver.o ./Drivers/hw_drivers/bluetooth_drivers/bluetooth_driver.su

.PHONY: clean-Drivers-2f-hw_drivers-2f-bluetooth_drivers

