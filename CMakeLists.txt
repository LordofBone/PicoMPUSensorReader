# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.13.1)

#include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C++ Standards
project(SensorReader C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

# point out the CMake, where to find the executable source file
add_executable(${PROJECT_NAME}
    main.cpp
	mpu6050.cpp
)

# include the directory for the mpu6050 header file
target_include_directories(${PROJECT_NAME} PUBLIC inc/
)

# enable usb output, disable uart output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
pico_add_extra_outputs(${PROJECT_NAME})

# Pull in our pico_stdlib which pulls in commonly used features (gpio, timer-delay etc)
target_link_libraries(${PROJECT_NAME} pico_stdlib hardware_gpio hardware_i2c hardware_pio hardware_pwm pico_multicore)