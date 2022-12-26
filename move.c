#include "move.h"

static void throw_error(char *msg) {
    fprintf(stderr, "[error] %s\n", msg);
    exit(EXIT_FAILURE);
}
static void test_pointer(void *p, char *msg) {
    if (p == NULL)
        throw_error(msg);
}

move move_create(uint row, uint col, square s, game g) {
    move m = malloc(sizeof(struct move_s));
    test_pointer(m, "move_create: malloc failed");
    m->row = row;
    m->col = col;
    m->s = s;
    m->prev = game_get_square(g, row, col);
    return m;
}

void move_delete(move m) {
    if (m != NULL)
        free(m);
}

void move_print(move m) {
    test_pointer(m, "move_print: move is NULL");
    printf("move: row=%d, col=%d, square=%d\n", m->row, m->col, m->s);
}
