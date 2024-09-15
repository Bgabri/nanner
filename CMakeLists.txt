cmake_minimum_required(VERSION 3.10)
project(Nanner)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES "src/*.c")
add_executable(nnr ${SOURCES})
install(TARGETS nnr DESTINATION bin)
