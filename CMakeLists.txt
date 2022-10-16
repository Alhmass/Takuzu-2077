cmake_minimum_required(VERSION 2.6)
project(game_text C)

set(CMAKE_C_FLAGS "-std=c99 -Wall -g")

file(GLOB_RECURSE game_text_src src/*.c)

include_directories(include)

add_executable(game_text ${game_text_src})

target_link_libraries(game_text ${CMAKE_SOURCE_DIR}/lib/libgame.a)