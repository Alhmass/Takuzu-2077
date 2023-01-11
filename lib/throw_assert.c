#include "takuzu.h"

bool throw_error(char *msg) {
    if (!msg)
        return false;
    fprintf(stderr, "[error] %s\n", msg);
    exit(EXIT_FAILURE);
}

bool game_test(game g, char *msg) {
    if (!g)
        throw_error(msg);
    return true;
}

bool cgame_test(cgame g, char *msg) {
    if (!g)
        throw_error(msg);
    return true;
}

bool pointer_test(void *ptr, char *msg) {
    if (!ptr)
        throw_error(msg);
    return true;
}
