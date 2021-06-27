################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Calculadora-tp1.c \
../src/funcionesCalculadora.c \
../src/validaciones.c 

OBJS += \
./src/Calculadora-tp1.o \
./src/funcionesCalculadora.o \
./src/validaciones.o 

C_DEPS += \
./src/Calculadora-tp1.d \
./src/funcionesCalculadora.d \
./src/validaciones.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


