add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest)

set(TEST_BINARY ${PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)
foreach(TEST_FILE ${TEST_FILES})
  add_executable(${TEST_BINARY} ${TEST_FILE})
  target_link_libraries(${TEST_BINARY} UULP)
endforeach()

target_link_libraries(${TEST_BINARY} gtest gtest_main)
add_test(NAME    ${TEST_BINARY}
         COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY})  