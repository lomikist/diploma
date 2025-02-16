add_executable(test_parser
  test_parser.cpp
  ../../src/parser/parser.cpp
)

target_include_directories(test_parser PRIVATE ../../inc)

add_test(NAME ParserTests COMMAND test_parser)

