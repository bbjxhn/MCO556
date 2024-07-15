################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_MK64F12.c 

C_DEPS += \
./device/system_MK64F12.d 

OBJS += \
./device/system_MK64F12.o 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c device/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\jmtri\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_2btn\board" -I"C:\Users\jmtri\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_2btn\source" -I"C:\Users\jmtri\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_2btn\utilities" -I"C:\Users\jmtri\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_2btn\drivers" -I"C:\Users\jmtri\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_2btn\device" -I"C:\Users\jmtri\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_2btn\component\serial_manager" -I"C:\Users\jmtri\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_2btn\component\lists" -I"C:\Users\jmtri\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_2btn\CMSIS" -I"C:\Users\jmtri\Desktop\MCO 556\Lab 6 - Pulse Width Modulation (PWM)\Lab6_PWM_pinPTC2_2btn\component\uart" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-device

clean-device:
	-$(RM) ./device/system_MK64F12.d ./device/system_MK64F12.o

.PHONY: clean-device

