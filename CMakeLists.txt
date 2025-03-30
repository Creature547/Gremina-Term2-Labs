cmake_minimum_required(VERSION 3.10)
project(PlanetDB)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создание статической библиотеки Planet
add_library(Planet STATIC
    Planet.cpp
    Planet.h
)

# Создание исполняемого файла
add_executable(planets
    main.cpp
)

# Линковка библиотеки с исполняемым файлом
target_link_libraries(planets Planet)

# Настройка директорий включения
target_include_directories(Planet PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Включение дополнительных предупреждений
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(planets PRIVATE -Wall -Wextra -Wpedantic)
endif()
