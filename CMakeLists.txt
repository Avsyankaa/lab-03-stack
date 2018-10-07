cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include("gate/cmake/HunterGate.cmake")

HunterGate(
  URL "https://github.com/ruslo/hunter/archive/v0.23.31.tar.gz"
  SHA1 "3d94b8522541c4c8eaac606f4c47d09322a8019c"
)

project(stack)

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)

string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -Wno-unused-command-line-argument -Wshadow -Wnon-virtual-dtor -pedantic")

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_executable(stack_tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/init.cpp)
target_link_libraries(stack_tests GTest::main)

enable_testing()
add_test(NAME tests COMMAND stack_tests) 

# Для упрощения работы с данным конфигурационным файлом был сделан ряд изменений
# 1. Вместо функции `target_include_directories` используется функция `include_directories`
# 2. Вместо использования "header only" библиотеки, в вызов `include_directories` добавляется директория *include*.
# 3. Вмсето подключения скрипта валидатора файлов исходного кода *cpplint*, как submodule, используется прямое подключение.
# В промышленных проектах данный ряд упрощений будет не приемлем.
