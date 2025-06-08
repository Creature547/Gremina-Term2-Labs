cmake_minimum_required(VERSION 3.20)

project(lab7)

set(CMAKE_CXX_STANDARD 20)

set(LIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/MyClasses.cpp
)

set(LIB_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/MyClasses.h
)
add_library(MyLibrary STATIC ${LIB_SOURCES} ${LIB_HEADERS})

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE MyLibrary)
