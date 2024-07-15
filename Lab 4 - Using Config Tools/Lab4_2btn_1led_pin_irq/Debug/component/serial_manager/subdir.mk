################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/serial_manager/fsl_component_serial_manager.c \
../component/serial_manager/fsl_component_serial_port_uart.c 

C_DEPS += \
./component/serial_manager/fsl_component_serial_manager.d \
./component/serial_manager/fsl_component_serial_port_uart.d 

OBJS += \
./component/serial_manager/fsl_component_serial_manager.o \
./component/serial_manager/fsl_component_serial_port_uart.o 


# Each subdirectory must supply rules for building sources it contributes
component/serial_manager/%.o: ../component/serial_manager/%.c component/serial_manager/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led_pin_irq\board" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led_pin_irq\source" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led_pin_irq\utilities" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led_pin_irq\drivers" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led_pin_irq\device" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led_pin_irq\component\serial_manager" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led_pin_irq\component\lists" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led_pin_irq\CMSIS" -I"E:\MCO 556\Lab 4 - Using Config Tools\Lab4_2btn_1led_pin_irq\component\uart" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-component-2f-serial_manager

clean-component-2f-serial_manager:
	-$(RM) ./component/serial_manager/fsl_component_serial_manager.d ./component/serial_manager/fsl_component_serial_manager.o ./component/serial_manager/fsl_component_serial_port_uart.d ./component/serial_manager/fsl_component_serial_port_uart.o

.PHONY: clean-component-2f-serial_manager

