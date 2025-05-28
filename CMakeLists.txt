cmake_minimum_required(VERSION 3.10)
project(STL_Lab_8)

set(CMAKE_CXX_STANDARD 17)

# Собираем все задания и main
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

# Копировать input.txt в директорию сборки после компиляции (если есть input.txt)
add_custom_command(TARGET stl_lab POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/input.txt
        $<TARGET_FILE_DIR:stl_lab>/input.txt
)
