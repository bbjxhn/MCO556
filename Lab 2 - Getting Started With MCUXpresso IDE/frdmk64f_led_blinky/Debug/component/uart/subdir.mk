################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/uart/fsl_adapter_uart.c 

C_DEPS += \
./component/uart/fsl_adapter_uart.d 

OBJS += \
./component/uart/fsl_adapter_uart.o 


# Each subdirectory must supply rules for building sources it contributes
component/uart/%.o: ../component/uart/%.c component/uart/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DFRDM_K64F -DFREEDOM -DMCUXPRESSO_SDK -DCPU_MK64FN1M0VLL12_cm4 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_led_blinky\source" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_led_blinky\utilities" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_led_blinky\drivers" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_led_blinky\device" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_led_blinky\component\uart" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_led_blinky\component\lists" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_led_blinky\CMSIS" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_led_blinky\board" -O0 -fno-common -g3 -gdwarf-4 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-component-2f-uart

clean-component-2f-uart:
	-$(RM) ./component/uart/fsl_adapter_uart.d ./component/uart/fsl_adapter_uart.o

.PHONY: clean-component-2f-uart

