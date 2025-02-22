
cmake_minimum_required(VERSION 3.14)
project(Diploma)

set(CMAKE_BUILD_TYPE Debug)

include_directories(
    inc
    inc/parser
    inc/model
    inc/core
    inc/core/editor
    inc/core/select
    inc/core/fitness
    inc/core/crossover
)

file(GLOB MODEL_SOURCES src/model/*.cpp)
file(GLOB PARSER_SOURCES src/parser/*.cpp)

file(GLOB CORE_SOURCES 
    src/core/*.cpp
    src/core/editor/*.cpp 
    src/core/select/*.cpp 
    src/core/fitness/*.cpp 
    src/core/crossover/*.cpp
)

add_library(diploma_lib STATIC
    ${MODEL_SOURCES}
    ${PARSER_SOURCES}
    ${CORE_SOURCES}
)

add_executable(diploma src/main.cpp)

target_link_libraries(diploma diploma_lib)

enable_testing()
add_subdirectory(test/core)
add_subdirectory(test/model)


