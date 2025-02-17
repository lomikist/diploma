add_executable(test_core
  test_core.cpp
  ../../src/model/cell.cpp
  ../../src/model/chromosome.cpp
  ../../src/core/fitness/fitness_manhattan.cpp 
)

target_include_directories(test_core PRIVATE ../../inc)

add_test(NAME CoreTests COMMAND test_core)

