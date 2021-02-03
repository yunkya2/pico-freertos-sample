cmake_minimum_required(VERSION 3.12)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(pico_freertos_samples)

# initialize the Pico SDK
pico_sdk_init()

# rest of your project

add_subdirectory(freertos)
add_subdirectory(blink)
add_subdirectory(divcheck)
add_subdirectory(blink2)
