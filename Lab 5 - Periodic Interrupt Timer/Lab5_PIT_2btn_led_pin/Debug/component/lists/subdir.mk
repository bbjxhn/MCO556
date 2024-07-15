################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/lists/fsl_component_generic_list.c 

C_DEPS += \
./component/lists/fsl_component_generic_list.d 

OBJS += \
./component/lists/fsl_component_generic_list.o 


# Each subdirectory must supply rules for building sources it contributes
component/lists/%.o: ../component/lists/%.c component/lists/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\board" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\source" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\utilities" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\drivers" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\device" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\component\serial_manager" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\component\lists" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\CMSIS" -I"C:\Users\jmtri\OneDrive\Desktop\MCO 556\Lab 5 - Periodic Interrupt Timer\Lab5_PIT_2btn_led_pin\component\uart" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-component-2f-lists

clean-component-2f-lists:
	-$(RM) ./component/lists/fsl_component_generic_list.d ./component/lists/fsl_component_generic_list.o

.PHONY: clean-component-2f-lists

