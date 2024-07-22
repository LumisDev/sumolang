cmake_minimum_required(VERSION 3.5)
project(sumolang)
set(CMAKE_TOOLCHAIN_FILE ./toolchain/compile.cmake)

add_executable(sumo src/main.c)