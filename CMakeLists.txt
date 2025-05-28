cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

set(project "lab6")
project(${project})

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/term.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/polynomial.cpp
)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

