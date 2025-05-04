cmake_minimum_required(VERSION 3.10)
project(lab_3 LANGUAGES CXX)

add_executable(lab_3
    main.cpp         # Основной файл с main()
    src/app.cpp          # Реализация app
    fraction/fraction.cpp # Реализация Fraction
)

target_include_directories(lab_3 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/fraction
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
