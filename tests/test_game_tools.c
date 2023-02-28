#include "takuzu.h"

bool test_game_load() {
    FILE *f_default = fopen("../saves/game/default.txt", "r");
    if (f_default == NULL) {
        return false;
    }
    game g_default = game_load("../saves/game/default.txt");
    if (g_default == NULL) {
        fclose(f_default);
        return false;
    }
    uint nb_rows, nb_cols, wrapping, unique;
    if (fscanf(f_default, "%u %u %u %u\n", &nb_rows, &nb_cols, &wrapping, &unique) != 4) {
        fclose(f_default);
        game_delete(g_default);
        return false;
    }
    if (nb_rows != game_nb_rows(g_default) || nb_cols != game_nb_cols(g_default) ||
        game_is_wrapping(g_default) != wrapping || game_is_unique(g_default) != unique) {
        fclose(f_default);
        game_delete(g_default);
        return false;
    }
    for (uint i = 0; i < game_nb_cols(g_default); i++) {
        for (uint j = 0; j < game_nb_rows(g_default); j++) {
            char input;
            square s;
            if (fscanf(f_default, "%c", &input) != 1) {
                fclose(f_default);
                game_delete(g_default);
                return false;
            }
            if (input == 'e')
                s = S_EMPTY;
            else if (input == 'w')
                s = S_ZERO;
            else if (input == 'W')
                s = S_IMMUTABLE_ZERO;
            else if (input == 'b')
                s = S_ONE;
            else if (input == 'B')
                s = S_IMMUTABLE_ONE;
            else {
                fclose(f_default);
                game_delete(g_default);
                return false;
            }
            if (s != game_get_square(g_default, i, j)) {
                fclose(f_default);
                game_delete(g_default);
                return false;
            }
        }
        fscanf(f_default, "\n");
    }
    fclose(f_default);
    game_delete(g_default);

    FILE *f_test = fopen("../saves/game/test.txt", "r");
    if (f_test == NULL) {
        return false;
    }
    game g2 = game_load("../saves/game/test.txt");
    if (g2 == NULL) {
        fclose(f_test);
        return false;
    }
    if (fscanf(f_test, "%u %u %u %u\n", &nb_rows, &nb_cols, &wrapping, &unique) != 4) {
        fclose(f_test);
        game_delete(g2);
        return false;
    }
    if (nb_rows != game_nb_rows(g2) || nb_cols != game_nb_cols(g2) || game_is_wrapping(g2) != wrapping ||
        game_is_unique(g2) != unique) {
        fclose(f_test);
        game_delete(g2);
        return false;
    }
    for (uint i = 0; i < game_nb_cols(g2); i++) {
        for (uint j = 0; j < game_nb_rows(g2); j++) {
            char input;
            square s;
            if (fscanf(f_test, "%c", &input) != 1) {
                fclose(f_test);
                game_delete(g2);
                return false;
            }
            if (input == 'e')
                s = S_EMPTY;
            else if (input == 'w')
                s = S_ZERO;
            else if (input == 'W')
                s = S_IMMUTABLE_ZERO;
            else if (input == 'b')
                s = S_ONE;
            else if (input == 'B')
                s = S_IMMUTABLE_ONE;
            else {
                fclose(f_test);
                game_delete(g2);
                return false;
            }
            if (s != game_get_square(g2, i, j)) {
                fclose(f_test);
                game_delete(g2);
                return false;
            }
        }
        fscanf(f_test, "\n");
    }
    fclose(f_test);
    game_delete(g2);
    return true;
}

bool test_game_save() {
    game g = game_default();
    game g_ext = game_new_empty_ext(8, 8, true, false);
    game_set_square(g_ext, 0, 1, S_IMMUTABLE_ONE);
    game_set_square(g_ext, 0, 1, S_IMMUTABLE_ZERO);
    game_set_square(g_ext, 5, 7, S_IMMUTABLE_ZERO);
    game_set_square(g_ext, 4, 7, S_ZERO);
    game_set_square(g_ext, 3, 7, S_ONE);

    if (!g || !g_ext)
        return false;
    game_save(g, "default.txt");
    game_save(g_ext, "test_ext.txt");
    game_delete(g);
    FILE *f_save = fopen("./default.txt", "r");
    if (!f_save)
        return false;
    FILE *f_ext = fopen("./test_ext.txt", "r");
    if (!f_ext) {
        fclose(f_save);
        return false;
    }
    FILE *f_test = fopen("../saves/game/default.txt", "r");
    if (!f_test) {
        fclose(f_save);
        fclose(f_ext);
        return false;
    }
    uint rows_s, cols_s, wrapping_s, unique_s;
    if (fscanf(f_save, "%u %u %u %u\n", &rows_s, &cols_s, &wrapping_s, &unique_s) != 4) {
        fclose(f_test);
        fclose(f_save);
        return false;
    }
    uint rows_d, cols_d, wrapping_d, unique_d;
    if (fscanf(f_test, "%u %u %u %u\n", &rows_d, &cols_d, &wrapping_d, &unique_d) != 4) {
        fclose(f_test);
        fclose(f_save);
        return false;
    }
    if (rows_s != rows_d || cols_s != cols_d || wrapping_s != wrapping_d || unique_s != unique_d) {
        fclose(f_test);
        fclose(f_save);
        return false;
    }
    uint nb_rows, nb_cols, wrapping, unique;
    if (fscanf(f_ext, "%u %u %u %u\n", &nb_rows, &nb_cols, &wrapping, &unique) != 4) {
        fclose(f_test);
        fclose(f_save);
        fclose(f_ext);
        game_delete(g_ext);
        return false;
    }
    if (nb_rows != game_nb_rows(g_ext) || nb_cols != game_nb_cols(g_ext) || game_is_wrapping(g_ext) != wrapping ||
        game_is_unique(g_ext) != unique) {
        fclose(f_test);
        fclose(f_save);
        fclose(f_ext);
        game_delete(g_ext);
        return false;
    }
    for (uint i = 0; i < cols_s; i++) {
        for (uint j = 0; j < rows_s; j++) {
            char s_save;
            char s_def;
            if (fscanf(f_save, "%c", &s_save) != 1) {
                fclose(f_test);
                fclose(f_save);
                fclose(f_ext);
                game_delete(g_ext);
                return false;
            }
            if (fscanf(f_test, "%c", &s_def) != 1) {
                fclose(f_test);
                fclose(f_save);
                fclose(f_ext);
                game_delete(g_ext);
                return false;
            }
            if (s_def != s_save) {
                fclose(f_test);
                fclose(f_save);
                fclose(f_ext);
                game_delete(g_ext);
                return false;
            }
        }
        fscanf(f_save, "\n");
        fscanf(f_test, "\n");
    }
    fclose(f_test);
    fclose(f_save);
    for (uint i = 0; i < game_nb_cols(g_ext); i++) {
        for (uint j = 0; j < game_nb_rows(g_ext); j++) {
            char input;
            square s;
            if (fscanf(f_ext, "%c", &input) != 1) {
                fclose(f_ext);
                game_delete(g_ext);
                return false;
            }
            if (input == 'e')
                s = S_EMPTY;
            else if (input == 'w')
                s = S_ZERO;
            else if (input == 'W')
                s = S_IMMUTABLE_ZERO;
            else if (input == 'b')
                s = S_ONE;
            else if (input == 'B')
                s = S_IMMUTABLE_ONE;
            else {
                fclose(f_ext);
                game_delete(g_ext);
                return false;
            }
            if (s != game_get_square(g_ext, i, j)) {
                fclose(f_ext);
                game_delete(g_ext);
                return false;
            }
        }
        fscanf(f_ext, "\n");
    }
    fclose(f_ext);
    game_delete(g_ext);
    return true;
}

bool test_game_solve() {
    game g = game_load("../saves/game/default.txt");
    game solution = game_load("../saves/game/solution.txt");
    game g2 = game_load("../saves/game/4x4_0.txt");
    game g3 = game_load("../saves/game/4x4_1.txt");
    game g4 = game_load("../saves/game/4x4_72.txt");
    bool status = true;

    if (!g || !solution || !g2 || !g3 || !g4)
        return false;
    if (!game_solve(g) || game_solve(g2) || !game_solve(g3) || !game_solve(g4))
        status = false;
    if (!game_equal(g, solution))
        status = false;
    if (!game_is_over(g) || !game_is_over(g3) || !game_is_over(g4))
        status = false;
    game_delete(g);
    game_delete(solution);
    game_delete(g2);
    game_delete(g3);
    game_delete(g4);
    return status;
}

bool test_game_nb_solutions() {
    game g = game_load("../saves/game/default.txt");
    game g2 = game_load("../saves/game/4x4_0.txt");
    game g3 = game_load("../saves/game/4x4_1.txt");
    game g4 = game_load("../saves/game/4x4_72.txt");
    game g5 = game_load("../saves/game/4x4_90.txt");
    bool status = true;

    if (!g || !g2 || !g3 || !g4 || !g5)
        return false;
    if (game_nb_solutions(g) != 1 || game_nb_solutions(g2) != 0 || game_nb_solutions(g3) != 1)
        status = false;
    if (game_nb_solutions(g4) != 72 || game_nb_solutions(g5) != 90)
        status = false;
    game_delete(g);
    game_delete(g2);
    game_delete(g3);
    game_delete(g4);
    game_delete(g5);
    return status;
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
    if (strcmp("game_load", argv[1]) == 0)
        pass = test_game_load();
    else if (strcmp("game_save", argv[1]) == 0)
        pass = test_game_save();
    else if (strcmp("game_solve", argv[1]) == 0)
        pass = test_game_solve();
    else if (strcmp("game_nb_solutions", argv[1]) == 0)
        pass = test_game_nb_solutions();
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