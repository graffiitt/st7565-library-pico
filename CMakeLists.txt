cmake_minimum_required(VERSION 3.12)
set(PICO_BOARD pico_w)
include(pico_sdk_import.cmake)

project(st7565 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_BUILD_TYPE Release)

pico_sdk_init()

file(GLOB CPPFILE "st7565/*.c")

message("Adding ${PROJECT_NAME} C files: " )
foreach(source ${CPPFILE})
    message("  - " ${source})
endforeach(source)


file(GLOB HFILE "st7565/*.h")

message("Adding ${PROJECT_NAME} H files: " )
foreach(source ${HFILE})
    message("  - " ${source})
endforeach(source)
add_executable(${PROJECT_NAME}
main.c
${CPPFILE}
${HFILE}
)

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_spi
    )
#pico_enable_stdio_usb(blink 0)
#pico_enable_stdio_uart(blink 1)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    )
pico_add_extra_outputs(${PROJECT_NAME})