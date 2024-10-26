cmake_minimum_required(VERSION 3.10)
project(StoreMart)

include(CTest)
enable_testing()

include_directories(inc)

set(SOURCES src/main.cpp)

add_executable(StoreMart ${SOURCES})

set_property(TARGET StoreMart PROPERTY CXX_STANDARD 23)
set_property(TARGET StoreMart PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET StoreMart PROPERTY CXX_EXTENSIONS OFF)
