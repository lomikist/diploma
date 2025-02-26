cmake_minimum_required(VERSION 3.14)
project(Diploma)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

file(GLOB MODEL_SOURCES src/model/*.cpp)
file(GLOB PARSER_SOURCES src/parser/*.cpp)
file(GLOB CORE_SOURCES 
    src/core/*.cpp
    src/core/crossover/*.cpp
    src/core/editor/*.cpp 
    src/core/fitness/*.cpp 
    src/core/mutate/*.cpp 
    src/core/select/*.cpp 
    src/gui/*.cpp 
)

add_library(diploma_lib STATIC
    ${MODEL_SOURCES}
    ${PARSER_SOURCES}
    ${CORE_SOURCES}
)

target_include_directories(diploma_lib PUBLIC 
    inc
    inc/parser
    inc/model
    inc/core
    inc/core/crossover
    inc/core/editor
    inc/core/fitness
    inc/core/mutate
    inc/core/select
    inc/gui
)

target_link_libraries(diploma_lib PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

add_executable(diploma src/main.cpp)

target_link_libraries(diploma PRIVATE diploma_lib Qt6::Core Qt6::Gui Qt6::Widgets)

enable_testing()

add_subdirectory(test/core)
add_subdirectory(test/model)
add_subdirectory(test/parser)

