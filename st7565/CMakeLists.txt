cmake_minimum_required (VERSION 3.8)
set(TARGET_NAME st7565)

message("Adding ${TARGET_NAME} C files: " )
file(GLOB CPPFILE "*.c")
foreach(source ${CPPFILE})
    message("  - " ${source})
endforeach(source)
 
message("Adding ${TARGET_NAME} H files: " )
file(GLOB HFILE "*.h")
foreach(source ${HFILE})
    message("  - " ${source})
endforeach(source)
 
add_library(${TARGET_NAME} STATIC
${CPPFILE}
${HFILE}
)

target_link_libraries(${TARGET_NAME}
pico_stdlib
hardware_spi
)

target_include_directories(${TARGET_NAME} PUBLIC
${CMAKE_CURRENT_LIST_DIR}
)