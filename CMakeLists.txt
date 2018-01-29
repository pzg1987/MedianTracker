cmake_minimum_required(VERSION 3.10.2)
project(MedianTracker)
file(GLOB SOURCES "src/*.cpp")
add_executable(MedianTracker ${SOURCES})