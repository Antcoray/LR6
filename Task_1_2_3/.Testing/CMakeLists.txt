cmake_minimum_required(VERSION 3.22)
project(ProjecT)

enable_testing()

add_executable(Task_1_TESTS Task_1_TESTS.cpp)
add_executable(Task_2_TESTS Task_2_TESTS.cpp)
add_executable(Task_3_TESTS Task_3_TESTS.cpp)

target_link_libraries(Task_1_TESTS gtest gtest_main)
target_link_libraries(Task_2_TESTS gtest gtest_main)
target_link_libraries(Task_3_TESTS gtest gtest_main)

add_test(NAME Task_1_TESTS COMMAND Task_1_TESTS)
add_test(NAME Task_2_TESTS COMMAND Task_2_TESTS)
add_test(NAME Task_3_TESTS COMMAND Task_3_TESTS)