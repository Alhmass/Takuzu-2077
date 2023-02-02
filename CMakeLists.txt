# ---- Project Settings ---- #
cmake_minimum_required(VERSION 2.6)
project(game_text C)
include(CTest)
enable_testing()

# ---- Pre Processor Intructions ---- #
include_directories(include)

# ---- Library Generation ---- #
file(GLOB_RECURSE game_lib_src lib/*.c)
add_library(game ${game_lib_src})

# ---- Compilation Rules ---- #
set(CMAKE_C_FLAGS "-std=c99 -Wall -Wextra -Werror -g")
file(GLOB_RECURSE game_text_src src/*.c)
link_directories(${CMAKE_SOURCE_DIR})
link_libraries(game)

# ---- Binary Generation ---- #
add_executable(game_text ${game_text_src})

# ---- Tests Generation ---- #
add_executable(test_game                    tests/test_game.c)
add_test(test_game_new                      ./test_game game_new)
add_test(test_game_new_empty                ./test_game game_new_empty)
add_test(test_game_copy                     ./test_game game_copy)
add_test(test_game_equal                    ./test_game game_equal)
add_test(test_game_delete                   ./test_game game_delete)
add_test(test_game_is_empty                 ./test_game game_is_empty)
add_test(test_game_restart                  ./test_game game_restart)
add_test(test_game_set_square               ./test_game game_set_square)
add_test(test_game_get_square               ./test_game game_get_square)
add_test(test_game_get_number               ./test_game game_get_number)
add_test(test_game_get_next_square          ./test_game game_get_next_square)
add_test(test_game_get_next_number          ./test_game game_get_next_number)
add_test(test_game_is_immutable             ./test_game game_is_immutable)
add_test(test_game_has_error                ./test_game game_has_error)
add_test(test_game_check_move               ./test_game game_check_move)
add_test(test_game_play_move                ./test_game game_play_move)
add_test(test_game_is_over                  ./test_game game_is_over)

add_executable(test_game_aux                tests/test_game_aux.c)
add_test(test_game_default                  ./test_game_aux game_default)
add_test(test_game_default_solution         ./test_game_aux game_default_solution)
add_test(test_game_print                    ./test_game_aux game_print)

add_executable(test_game_ext                tests/test_game_ext.c)
add_test(test_game_new_ext                  ./test_game_ext game_new_ext)
add_test(test_game_new_empty_ext            ./test_game_ext game_new_empty_ext)
add_test(test_game_undo                     ./test_game_ext game_undo)
add_test(test_game_redo                     ./test_game_ext game_redo)
add_test(test_game_nb_rows                  ./test_game_ext game_nb_rows)
add_test(test_game_nb_cols                  ./test_game_ext game_nb_cols)
add_test(test_game_is_unique                ./test_game_ext game_is_unique)
add_test(test_game_is_wrapping              ./test_game_ext game_is_wrapping)

add_executable(test_v2                      tests/test_v2.c)
add_test(test_new_ext                       ./test_v2 new_ext)
add_test(test_new_empty_ext                 ./test_v2 new_empty_ext)
add_test(test_equal_ext                     ./test_v2 equal_ext)
add_test(test_copy_ext                      ./test_v2 copy_ext)
add_test(test_get_next_square_wrapping      ./test_v2 get_next_square_wrapping)
add_test(test_get_next_number_wrapping      ./test_v2 get_next_number_wrapping)
add_test(test_has_error_wrapping            ./test_v2 has_error_wrapping)
add_test(test_is_over_wrapping              ./test_v2 is_over_wrapping)
add_test(test_has_error_unique              ./test_v2 has_error_unique)
add_test(test_is_over_unique                ./test_v2 is_over_unique)
add_test(test_undo_one                      ./test_v2 undo_one)
add_test(test_undo_redo_some                ./test_v2 undo_redo_some)
add_test(test_undo_redo_all                 ./test_v2 undo_redo_all)
add_test(test_restart_undo                  ./test_v2 restart_undo)
