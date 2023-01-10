# ---- Project Settings ---- #
cmake_minimum_required(VERSION 2.6)
project(game_text C)
enable_testing()
include(CTest)

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
add_custom_command(TARGET game_text POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/lib/ ${CMAKE_SOURCE_DIR})

# ---- Tests Generation ---- #
add_executable(game_test_tlacault               tests/game_test_tlacault.c)
add_test(test_tlacault_game_new                 ./game_test_tlacault game_new)
add_test(test_tlacault_game_new_empty           ./game_test_tlacault game_new_empty)
add_test(test_tlacault_game_copy                ./game_test_tlacault game_copy)
add_test(test_tlacault_game_equal               ./game_test_tlacault game_equal)
add_test(test_tlacault_game_delete              ./game_test_tlacault game_delete)
add_test(test_tlacault_game_is_empty            ./game_test_tlacault game_is_empty)
add_test(test_tlacault_game_restart             ./game_test_tlacault game_restart)
add_test(test_tlacault_game_default             ./game_test_tlacault game_default)
add_test(test_tlacault_game_default_solution    ./game_test_tlacault game_default_solution)
add_test(test_tlacault_game_new_ext             ./game_test_tlacault game_new_ext)
add_test(test_tlacault_game_new_empty_ext       ./game_test_tlacault game_new_empty_ext)
add_test(test_tlacault_game_undo                ./game_test_tlacault game_undo)
add_test(test_tlacault_game_redo                ./game_test_tlacault game_redo)

add_executable(game_test_hlumet                 tests/game_test_hlumet.c)
add_test(test_hlumet_game_set_square            ./game_test_hlumet game_set_square)
add_test(test_hlumet_game_get_square            ./game_test_hlumet game_get_square)
add_test(test_hlumet_game_get_number            ./game_test_hlumet game_get_number)
add_test(test_hlumet_game_get_next_square       ./game_test_hlumet game_get_next_square)
add_test(test_hlumet_game_get_next_number       ./game_test_hlumet game_get_next_number)
add_test(test_hlumet_game_nb_rows               ./game_test_hlumet game_nb_rows)
add_test(test_hlumet_game_nb_cols               ./game_test_hlumet game_nb_cols)

add_executable(game_test_aloupoueyou            tests/game_test_aloupoueyou.c)
add_test(test_aloupoueyou_game_is_immutable     ./game_test_aloupoueyou game_is_immutable)
add_test(test_aloupoueyou_game_has_error        ./game_test_aloupoueyou game_has_error)
add_test(test_aloupoueyou_game_check_move       ./game_test_aloupoueyou game_check_move)
add_test(test_aloupoueyou_game_play_move        ./game_test_aloupoueyou game_play_move)
add_test(test_aloupoueyou_game_is_over          ./game_test_aloupoueyou game_is_over)
add_test(test_aloupoueyou_game_is_unique        ./game_test_aloupoueyou game_is_unique)
add_test(test_aloupoueyou_game_is_wrapping      ./game_test_aloupoueyou game_is_wrapping)
