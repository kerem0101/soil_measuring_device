################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/hw_drivers/lcd_drivers/LCD16x2.c \
../Drivers/hw_drivers/lcd_drivers/LCD16x2_cfg.c 

OBJS += \
./Drivers/hw_drivers/lcd_drivers/LCD16x2.o \
./Drivers/hw_drivers/lcd_drivers/LCD16x2_cfg.o 

C_DEPS += \
./Drivers/hw_drivers/lcd_drivers/LCD16x2.d \
./Drivers/hw_drivers/lcd_drivers/LCD16x2_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/hw_drivers/lcd_drivers/%.o Drivers/hw_drivers/lcd_drivers/%.su: ../Drivers/hw_drivers/lcd_drivers/%.c Drivers/hw_drivers/lcd_drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-hw_drivers-2f-lcd_drivers

clean-Drivers-2f-hw_drivers-2f-lcd_drivers:
	-$(RM) ./Drivers/hw_drivers/lcd_drivers/LCD16x2.d ./Drivers/hw_drivers/lcd_drivers/LCD16x2.o ./Drivers/hw_drivers/lcd_drivers/LCD16x2.su ./Drivers/hw_drivers/lcd_drivers/LCD16x2_cfg.d ./Drivers/hw_drivers/lcd_drivers/LCD16x2_cfg.o ./Drivers/hw_drivers/lcd_drivers/LCD16x2_cfg.su

.PHONY: clean-Drivers-2f-hw_drivers-2f-lcd_drivers

