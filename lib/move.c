#include "takuzu.h"

move move_create(uint row, uint col, square s, square p) {
    move m = malloc(sizeof(struct move_s));
    pointer_test(m, "move_create: malloc failed");
    m->row = row;
    m->col = col;
    m->s = s;
    m->p = p;
    return m;
}

void move_delete(move m) {
    if (m != NULL)
        free(m);
    m = NULL;
}

uint move_row(move m) {
    pointer_test(m, "move_row: move is NULL");
    return m->row;
}
uint move_col(move m) {
    pointer_test(m, "move_col: move is NULL");
    return m->col;
}
square move_s(move m) {
    pointer_test(m, "move_s: move is NULL");
    return m->s;
}
square move_p(move m) {
    pointer_test(m, "move_p: move is NULL");
    return m->p;
}

void move_print(move m) {
    pointer_test(m, "move_print: move is NULL");
    printf("[%d] [%d] [%d] [%d]\n", m->row, m->col, m->s, m->p);
}
