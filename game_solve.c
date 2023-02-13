#include "takuzu.h"

static void display_help(void) {
    printf("[Usage]\n");
    printf("./game_solve <option> <input> [<output>]\n");
}

int main(int ac, char **av) {
    if (ac < 3 || ac > 4)
        display_help();

    if (strcmp(av[1], "-s") == 0) {
        game g = game_load(av[2]);
        if (game_solve(g)) {
            if (ac == 4)
                game_save(g, av[3]);
            else
                game_print(g);
        } else {
            game_delete(g);
            exit(EXIT_FAILURE);
        }
        game_delete(g);
    } else if (strcmp(av[1], "-c") == 0) {
        game g = game_load(av[2]);
        uint nb_solutions = game_nb_solutions(g);
        if (ac == 4) {
            FILE *f = fopen(av[3], "w");
            if (f == NULL) {
                printf("Error: could not open file '%s' for writing\n", av[3]);
                exit(EXIT_FAILURE);
            }
            fprintf(f, "%d\n", nb_solutions);
            fclose(f);
        } else {
            printf("%d\n", nb_solutions);
            game_delete(g);
        }
    } else {
        display_help();
    }
    return EXIT_SUCCESS;
}