cmake_minimum_required(VERSION 3.5)

project(SampleTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SampleTest main.cpp)

install(TARGETS SampleTest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
