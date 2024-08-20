cmake_minimum_required(VERSION 3.12)
set(PICO_BOARD pico_w)
include(pico_sdk_import.cmake)

project(st7565_test C CXX ASM)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${PROJECT_NAME}
main.c
)
add_subdirectory(st7565)
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    st7565
    )

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    )
pico_add_extra_outputs(${PROJECT_NAME})
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 0)