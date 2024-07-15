################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/pin_mux.c 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/pin_mux.d 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/pin_mux.o 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c board/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DPRINTF_FLOAT_ENABLE=0 -DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 -DFRDM_K64F -DFREEDOM -DMCUXPRESSO_SDK -DCPU_MK64FN1M0VLL12_cm4 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=1 -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_hello_world\source" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_hello_world\utilities" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_hello_world\drivers" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_hello_world\device" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_hello_world\component\uart" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_hello_world\component\lists" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_hello_world\CMSIS" -I"E:\MCO 556\Lab 2 - Getting Started With MCUXpresso IDE\frdmk64f_hello_world\board" -O0 -fno-common -g3 -gdwarf-4 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-board

clean-board:
	-$(RM) ./board/board.d ./board/board.o ./board/clock_config.d ./board/clock_config.o ./board/pin_mux.d ./board/pin_mux.o

.PHONY: clean-board

