################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mk64f12.c 

C_DEPS += \
./startup/startup_mk64f12.d 

OBJS += \
./startup/startup_mk64f12.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led__pin_irq_toggle\board" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led__pin_irq_toggle\source" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led__pin_irq_toggle\utilities" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led__pin_irq_toggle\drivers" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led__pin_irq_toggle\device" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led__pin_irq_toggle\component\serial_manager" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led__pin_irq_toggle\component\lists" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led__pin_irq_toggle\CMSIS" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led__pin_irq_toggle\component\uart" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_mk64f12.d ./startup/startup_mk64f12.o

.PHONY: clean-startup

