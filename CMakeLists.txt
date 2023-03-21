# ---- Project Settings ---- #
cmake_minimum_required(VERSION 2.6)
project(game_text C)
include(CTest)
enable_testing()

# ---- Import SDL2 ---- #
include(SDL2.cmake)
message(STATUS "SDL2 include dir: ${SDL2_ALL_INC}")
message(STATUS "SDL2 all libraries: ${SDL2_ALL_LIBS}")


# ---- Pre Processor Intructions ---- #
include_directories(${SDL2_ALL_INC})

include_directories(include)
include_directories(include/text)
include_directories(include/solver)

include_directories(include/sdl)
include_directories(include/sdl/scenes)

# ---- Library Generation ---- #
file(GLOB_RECURSE game_lib_src lib/*.c)
file(GLOB_RECURSE game_graphical_src sdl/*.c)
add_library(game ${game_lib_src} ${game_graphical_src})

# ---- Compilation Options ---- #
set(CMAKE_C_FLAGS "-std=c99 -Wall -Wextra -g")          # options de compilation génériques
set(CMAKE_C_FLAGS_DEBUG "-O0 --coverage")               # options de compilation en mode Debug
set(CMAKE_C_FLAGS_RELEASE "-O3")                        # options de compilation en mode Release

# ---- Source Files ---- #
file(GLOB_RECURSE game_text_src src/game_text.c)
file(GLOB_RECURSE game_solve_src src/game_solve.c)
file(GLOB_RECURSE game_sdl_src src/game_sdl.c)
link_directories(${CMAKE_SOURCE_DIR})
link_libraries(game)

# ---- Binary Generation ---- #
add_executable(game_text ${game_text_src})
add_executable(game_solve ${game_solve_src})
add_executable(game_sdl ${game_sdl_src})
target_link_libraries(game_sdl ${SDL2_ALL_LIBS} m)

# ---- File Duplication ---- #
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/saves/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/saves/)

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

add_executable(test_game_tools              tests/test_game_tools.c)
add_test(test_game_load                     ./test_game_tools game_load)
add_test(test_game_save                     ./test_game_tools game_save)
add_test(test_game_solve                    ./test_game_tools game_solve)
add_test(test_game_nb_solutions             ./test_game_tools game_nb_solutions)

add_executable(test_game_solver             tests/test_game_solver.c)
add_test(test_solver_new                    ./test_game_solver solver_new)
add_test(test_solver_delete                 ./test_game_solver solver_delete)
add_test(test_find_solutions                ./test_game_solver find_solutions)
add_test(test_is_word_solution              ./test_game_solver is_word_solution)
add_test(test_copy_solution                 ./test_game_solver copy_solution)

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
