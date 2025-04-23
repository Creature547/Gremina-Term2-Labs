cmake_minimum_required(VERSION 3.10)
project(FractionLab)

set(CMAKE_CXX_STANDARD 17)

# Путь к заголовкам
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/fraction)

# Статическая библиотека
add_library(fraction STATIC
    fraction/fraction.cpp
    fraction/fraction.h
)

# Исполняемый файл
add_executable(main
    main.cpp
)

# Линковка
target_link_libraries(main fraction)
