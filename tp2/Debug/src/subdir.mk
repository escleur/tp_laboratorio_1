################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayEmployees.c \
../src/abmUI.c \
../src/main.c \
../src/utn.c 

OBJS += \
./src/ArrayEmployees.o \
./src/abmUI.o \
./src/main.o \
./src/utn.o 

C_DEPS += \
./src/ArrayEmployees.d \
./src/abmUI.d \
./src/main.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


