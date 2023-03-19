#include "takuzu.h"

bool test_solver_new() {
    square squares1[4 * 4] = {0, 1, 2, 0, 1, 1, 3, 0, 2, 1, 2, 1, 0, 1, 0, 0};
    game g1 = game_new_ext(4, 4, squares1, false, false);
    solver s1 = solver_new(g1, true);

    square squares3[4 * 4] = {1, 2, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0};
    game g3 = game_new_ext(4, 4, squares3, false, true);
    solver s3 = solver_new(g3, true);

    if (s1 != NULL && s3 != NULL) {
        if (s1->unique == true && s3->unique == true) {
            solver_delete(s1);
            solver_delete(s3);
            game_delete(g1);
            game_delete(g3);
            return true;
        }
    }
    solver_delete(s1);
    solver_delete(s3);
    game_delete(g1);
    game_delete(g3);
    return false;
}

bool test_solver_delete() {
    square squares1[4 * 4] = {0, 1, 2, 0, 1, 1, 3, 0, 2, 1, 2, 1, 0, 1, 0, 0};
    game g1 = game_new_ext(4, 4, squares1, false, false);
    solver s1 = solver_new(g1, true);

    square squares3[4 * 4] = {1, 2, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0};
    game g3 = game_new_ext(4, 4, squares3, false, true);
    solver s3 = solver_new(g3, true);

    solver_delete(s1);
    solver_delete(s3);
    game_delete(g1);
    game_delete(g3);
    return true;
}

bool test_find_solutions() {
    bool pass = true;
    game g = game_load("saves/game/4x4_2.txt");
    solver s = solver_new(g, true);
    find_solutions(g, s, 0);
    copy_solution(g, s);
    if (!game_is_over(g) || s->nb_solutions != 1)
        pass = false;
    solver_delete(s);
    game_delete(g);
    return pass;
}

bool test_is_word_solution() { return true; }

bool test_copy_solution() {
    bool pass = true;
    game g = game_load("saves/game/4x4_2.txt");
    solver s = solver_new(g, true);
    find_solutions(g, s, 0);
    copy_solution(g, s);
    square squares[4 * 4] = {
        S_IMMUTABLE_ONE, S_IMMUTABLE_ZERO, S_ZERO, S_ONE,  S_IMMUTABLE_ZERO, S_IMMUTABLE_ONE,  S_ONE, S_ZERO,
        S_IMMUTABLE_ONE, S_IMMUTABLE_ONE,  S_ZERO, S_ZERO, S_IMMUTABLE_ZERO, S_IMMUTABLE_ZERO, S_ONE, S_ONE};
    game g2 = game_new_ext(4, 4, squares, false, false);
    if (!game_equal(g, g2))
        pass = false;
    solver_delete(s);
    game_delete(g);
    game_delete(g2);
    return pass;
}

/*  USAGE  */
void usage(char *argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

/*  MAIN ROUTINE  */
int main(int argc, char *argv[]) {
    if (argc == 1)
        usage(argv);

    fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
    bool pass = false;
    if (strcmp("solver_new", argv[1]) == 0)
        pass = test_solver_new();
    else if (strcmp("solver_delete", argv[1]) == 0)
        pass = test_solver_delete();
    else if (strcmp("find_solutions", argv[1]) == 0)
        pass = test_find_solutions();
    else if (strcmp("is_word_solution", argv[1]) == 0)
        pass = test_is_word_solution();
    else if (strcmp("copy_solution", argv[1]) == 0)
        pass = test_copy_solution();
    else {
        fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (pass == true) {
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}