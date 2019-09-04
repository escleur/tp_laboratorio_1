################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/calculadora.c \
../src/funcionesMath.c \
../src/tp1.c 

OBJS += \
./src/calculadora.o \
./src/funcionesMath.o \
./src/tp1.o 

C_DEPS += \
./src/calculadora.d \
./src/funcionesMath.d \
./src/tp1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


