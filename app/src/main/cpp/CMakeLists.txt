cmake_minimum_required(VERSION 3.22.1)

project("tryvoicevox")

# native_lib
add_library(
        native_lib
        SHARED
        native_lib_wrap.cpp)

find_library(
        log-lib
        log)

target_link_libraries(
        native_lib
        Android
        ${log-lib})
