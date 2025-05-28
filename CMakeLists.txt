cmake_minimum_required(VERSION 3.10)
project(STL_Lab)

set(CMAKE_CXX_STANDARD 17)

# Устанавливаем выходной путь (куда будет собран исполняемый файл)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})  # то есть .build

# Добавляем все исходники
add_executable(stl_lab
    main.cpp
    task1.cpp
    task2.cpp
    task3.cpp
    task4.cpp
    task5.cpp
    task6.cpp
    task7.cpp
    task8.cpp
    task9.cpp
)

# Копируем input.txt в папку .build после сборки
add_custom_command(TARGET stl_lab POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/input.txt
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/input.txt
)
