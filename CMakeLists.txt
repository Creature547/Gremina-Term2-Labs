cmake_minimum_required(VERSION 3.10)
project(lab_4 LANGUAGES CXX)

add_library(stack STATIC stack/stack.cpp)
target_include_directories(stack PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/stack
)

add_executable(lab_4
    main.cpp
    src/app.cpp
)

target_link_libraries(lab_4 PRIVATE stack)

target_include_directories(lab_4 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
