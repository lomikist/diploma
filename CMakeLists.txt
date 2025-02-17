cmake_minimum_required(VERSION 3.14)
project(MyProject)

set(CMAKE_BUILD_TYPE Debug)

include_directories(
    inc
    inc/parser
    inc/model
    inc/core
    inc/core/editor
    inc/core/fitness
    inc/core/crossover
)

file(GLOB MODEL_SOURCES src/model/*.cpp)
file(GLOB PARSER_SOURCES src/parser/*.cpp)
file(GLOB CORE_SOURCES src/core/*.cpp)
file(GLOB CORE_SOURCES 
                    src/core/editor/*.cpp 
                    src/core/fitness/*.cpp 
                    src/core/crossover/*.cpp
)

add_executable(diploma
    src/main.cpp
    ${MODEL_SOURCES}
    ${PARSER_SOURCES}
    ${CORE_SOURCES} 
)

enable_testing()

add_subdirectory(test/parser)
add_subdirectory(test/model)
add_subdirectory(test/core)

