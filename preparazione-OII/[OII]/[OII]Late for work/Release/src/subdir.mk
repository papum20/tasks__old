################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/[OII]Late\ for\ work.cpp 

OBJS += \
./src/[OII]Late\ for\ work.o 

CPP_DEPS += \
./src/[OII]Late\ for\ work.d 


# Each subdirectory must supply rules for building sources it contributes
src/[OII]Late\ for\ work.o: ../src/[OII]Late\ for\ work.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/[OII]Late for work.d" -MT"src/[OII]Late\ for\ work.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


