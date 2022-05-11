cmake_minimum_required(VERSION 2.8.9)
project(v.10)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(v.01 ${SOURCES})
