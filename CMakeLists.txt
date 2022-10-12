cmake_minimum_required(VERSION 2.6)
project(game_text C)

set(CMAKE_C_FLAGS "-std=c99 -Wall -g")

add_executable(game_text game_text.c)

target_link_libraries(game_text ${CMAKE_SOURCE_DIR}/libgame.a)