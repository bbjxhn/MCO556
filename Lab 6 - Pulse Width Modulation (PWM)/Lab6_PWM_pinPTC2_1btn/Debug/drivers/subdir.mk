################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_adc16.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_ftm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c 

C_DEPS += \
./drivers/fsl_adc16.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_ftm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d 

OBJS += \
./drivers/fsl_adc16.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_ftm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_1btn\board" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_1btn\source" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_1btn\utilities" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_1btn\drivers" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_1btn\device" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_1btn\component\serial_manager" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_1btn\component\lists" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_1btn\CMSIS" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_1btn\component\uart" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_adc16.d ./drivers/fsl_adc16.o ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_ftm.d ./drivers/fsl_ftm.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_i2c.d ./drivers/fsl_i2c.o ./drivers/fsl_smc.d ./drivers/fsl_smc.o ./drivers/fsl_uart.d ./drivers/fsl_uart.o

.PHONY: clean-drivers

