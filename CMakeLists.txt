cmake_minimum_required(VERSION 3.10)
project(Lab3 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lab_3)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lab_3)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(fraction STATIC
    fraction/fraction.cpp
    fraction/fraction.hpp
)

target_include_directories(fraction PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/fraction
)

add_executable(lab_3
    main.cpp
    src/app.cpp
    src/app.hpp
)

target_link_libraries(lab_3 PRIVATE fraction)
target_include_directories(lab_3 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/fraction
)
