add_executable(test_model
  test_model.cpp
  ../../src/model/model.cpp
  ../../src/model/cell.cpp
  ../../src/model/chromosome.cpp
  ../../src/model/population.cpp
)

target_include_directories(test_model PRIVATE ../../inc)

add_test(NAME ModelTests COMMAND test_model)

