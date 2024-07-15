################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_adc16.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_pit.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c 

C_DEPS += \
./drivers/fsl_adc16.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_pit.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d 

OBJS += \
./drivers/fsl_adc16.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_pit.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\board" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\source" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\utilities" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\drivers" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\device" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\component\serial_manager" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\component\lists" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\CMSIS" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\component\uart" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_adc16.d ./drivers/fsl_adc16.o ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_i2c.d ./drivers/fsl_i2c.o ./drivers/fsl_pit.d ./drivers/fsl_pit.o ./drivers/fsl_smc.d ./drivers/fsl_smc.o ./drivers/fsl_uart.d ./drivers/fsl_uart.o

.PHONY: clean-drivers

