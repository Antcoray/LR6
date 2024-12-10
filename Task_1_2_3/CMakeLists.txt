cmake_minimum_required(VERSION 3.22)
project(Project)

add_executable(Task_1_2_3 main.cpp)

#Address Sanitizer
add_executable(AddressSan main.cpp)
target_compile_options(AddressSan PRIVATE -fsanitize=address)
target_link_options(AddressSan PRIVATE -fsanitize=address)

# Thread Sanitizer
add_executable(ThreadSan main.cpp)
target_compile_options(ThreadSan PRIVATE -fsanitize=thread)
target_link_options(ThreadSan PRIVATE -fsanitize=thread)
