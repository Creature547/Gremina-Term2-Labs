cmake_minimum_required(VERSION 3.10)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Planet STATIC
    Planet.cpp
    Planet.h
)

add_library(RailwayTicket STATIC
    RailwayTicket.cpp
    RailwayTicket.h
)

add_executable(main
    main.cpp
)

target_link_libraries(main
    PRIVATE
        Planet
        RailwayTicket
)

target_include_directories(Planet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(RailwayTicket PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(main PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()
