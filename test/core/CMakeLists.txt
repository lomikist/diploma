file(GLOB TEST_SOURCES *.cpp)

foreach(TEST_FILE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    add_executable(${TEST_NAME} ${TEST_FILE} ${TEST_DEPENDENCIES})

    target_link_libraries(${TEST_NAME} diploma_lib)    
    target_include_directories(${TEST_NAME} PRIVATE ../../inc)

    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

