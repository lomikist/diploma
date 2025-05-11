cmake_minimum_required(VERSION 3.14)
project(Diploma)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Boost REQUIRED COMPONENTS json)

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
    src/core/observer/*.cpp 
    src/core/vizualize/*.cpp 
    src/core/logger/*.cpp 
    src/gui/*.cpp 
)

qt6_wrap_cpp(MOC_SOURCES   
    inc/gui/main_window.hpp
    inc/gui/paint_area.hpp
    inc/gui/file_selector.hpp
    inc/gui/gui_controller.hpp
)

add_library(diploma_lib STATIC
    ${MOC_SOURCES}
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
    inc/core/observer
    inc/core/vizualize
    inc/core/logger
    inc/gui
)

target_link_libraries(diploma_lib PRIVATE Boost::json Qt6::Core Qt6::Gui Qt6::Widgets)

add_executable(diploma src/main.cpp)

target_link_libraries(diploma PRIVATE Boost::json diploma_lib Qt6::Core Qt6::Gui Qt6::Widgets)

enable_testing()

add_subdirectory(test/core)
add_subdirectory(test/model)
add_subdirectory(test/parser)

