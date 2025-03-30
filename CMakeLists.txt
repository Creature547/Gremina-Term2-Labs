cmake_minimum_required(VERSION 3.10)
project(PlanetDB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Planet STATIC
    Planet.cpp
    Planet.h
)

add_library(Database STATIC
    Database.cpp
    Database.h
)

add_executable(planets
    main.cpp
)

target_link_libraries(planets
    PRIVATE
        Planet
        Database
)

target_include_directories(Planet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Database PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(planets PRIVATE -Wall -Wextra -Wpedantic)
endif()
