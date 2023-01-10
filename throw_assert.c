#include "takuzu.h"

void throw_error(char *msg) {
    fprintf(stderr, "[error] %s\n", msg);
    exit(EXIT_FAILURE);
}

void game_test(game g, char *msg) {
    if (g == NULL)
        throw_error(msg);
}

void cgame_test(cgame g, char *msg) {
    if (g == NULL)
        throw_error(msg);
}

void pointer_test(void *ptr, char *msg) {
    if (ptr == NULL)
        throw_error(msg);
}