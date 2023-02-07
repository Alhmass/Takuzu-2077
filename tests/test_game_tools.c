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
    return true;
}

bool test_game_game_save() { return false; }

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
        pass = test_game_game_save();
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