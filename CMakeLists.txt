cmake_minimum_required(VERSION 3.4)

project(stack)

include("gate/cmake/HunterGate.cmake")

HunterGate(
  URL "https://github.com/ruslo/hunter/archive/v0.23.31.tar.gz"
  SHA1 "3d94b8522541c4c8eaac606f4c47d09322a8019c"
)

include(gtest.cmake)
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR})

string(APPEND CMAKE_CXX_FLAGS " -std=c++11 -O1 -fsanitize=address")
string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -Wno-unused-command-line-argument -Wshadow -Wnon-virtual-dtor -pedantic")

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_executable(executable 
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/init.cpp
)

target_link_libraries(executable GTest::main)

# Для упрощения работы с данным конфигурационным файлом был сделан ряд изменений
# 1. Вместо переменной `CMAKE_CXX_STANDARD` используется опция компилятора *-std=c++11*
# 2. Вместо функции `target_include_directories` используется функция `include_directories`
# 3. Фреймворк "Google Test" подключается не через пакетный менеджер Hunter, а через конфигурационный файл *gtest.cmake*
# 4. Вместо создание отдельной цели для построение "header only" библиотеки в вызов `include_directories` добавляется `.`
# 5. Вместо переменной `CMAKE_CURRENT_SOURCE_DIR` используется символ `.`, обозначающий текущую директорию.
# 6. Вмсето подключения скрипта валидатора файлов исходного кода *cpplint*, как submodule, используется прямое подключение.
# 7. Вместо функции `add_test` используется функция `add_executable`.
# 8. Вместо кросплатформенного санитайзера *sanitize-address* используется ручное изменение флагов.
# В промышленных проектах данный ряд упрощений будет не приемлем.
