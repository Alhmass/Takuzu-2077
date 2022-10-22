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
add_executable(game_test_tlacault tests/game_test_tlacault.c)
add_test(test_tlacault_dummy ./game_test_tlacault dummy)

add_executable(game_test_hlumet tests/game_test_hlumet.c)
add_test(test_hlumet_dummy ./game_test_hlumet dummy)

add_executable(game_test_aloupoueyou tests/game_test_aloupoueyou.c)
add_test(test_aloupoueyou_dummy ./game_test_aloupoueyou dummy)
