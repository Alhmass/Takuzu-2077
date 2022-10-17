# ---- Project Settings ---- #
cmake_minimum_required(VERSION 2.6)
project(game_text C)
enable_testing()

# ---- Compilation Rules ---- #
set(CMAKE_C_FLAGS "-std=c99 -Wall -g")
file(GLOB_RECURSE game_text_src src/*.c)
include_directories(include)
link_directories(${CMAKE_SOURCE_DIR}/lib)
link_libraries(game)

# ---- Binary Generation ---- #
add_executable(game_text ${game_text_src})

# ---- Tests Generation ---- #
add_executable(game_test_tim.lacault@etu.u-bordeaux.fr tests/game_test_tim.lacault@etu.u-bordeaux.fr.c)
add_test(game_test_tim.lacault@etu.u-bordeaux.fr_dummy ./game_test_tim.lacault@etu.u-bordeaux.fr dummy)

add_executable(game_test_hugo.lumet@etu.u-bordeaux.fr ${CMAKE_SOURCE_DIR}/tests/game_test_hugo.lumet@etu.u-bordeaux.fr)
add_test(test_hugo.lumet@etu.u-bordeaux.fr_dummy ./game_test_hugo.lumet@etu.u-bordeaux.fr dummy)

add_executable(game_test_alexandre.lou-poueyou@etu.u-bordeaux.fr tests/game_test_alexandre.lou-poueyou@etu.u-bordeaux.fr.c)
add_test(game_test_alexandre.lou-poueyou@etu.u-bordeaux.fr_dummy ./game_test_alexandre.lou-poueyou@etu.u-bordeaux.fr dummy)
