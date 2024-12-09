# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Имя проекта
project(MyProject)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем флаги компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=thread -fno-omit-frame-pointer")

# Указываем список исходных файлов
set(SOURCES
    Task_1_2_3.cpp
)

# Создаём исполняемый файл
add_executable(my_program ${SOURCES})