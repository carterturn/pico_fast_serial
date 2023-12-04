cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(fast_serial_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(fast_serial)
target_sources(fast_serial PUBLIC fast_serial_test.c fast_serial.c)

target_include_directories(fast_serial PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(fast_serial pico_stdlib pico_unique_id tinyusb_device tinyusb_board)

pico_add_extra_outputs(fast_serial)
