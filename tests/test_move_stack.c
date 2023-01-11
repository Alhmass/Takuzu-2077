#include "takuzu.h"

bool test_ms_create() {
    bool pass = true;
    ms stack = ms_create(5);
    if (stack == NULL || stack->data == NULL || stack->size != 0 || stack->capacity != 5)
        pass = false;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_delete() {
    bool pass = true;
    ms stack = ms_create(5);
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_double_capacity() {
    bool pass = true;
    ms stack = ms_create(2);
    ms_double_capacity(stack);
    if (stack->capacity != 4)
        pass = false;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_top() {
    bool pass = true;
    ms stack = ms_create(2);
    move m = move_create(1, 2, S_ONE, S_ZERO);
    ms_push(stack, m);
    move m2 = ms_top(stack);
    if (m2->row != 1 || m2->col != 2 || m2->s != S_ONE || m2->p != S_ZERO)
        pass = false;
    ms_delete(stack);
    stack = NULL;
    move_delete(m);
    m = NULL;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_push() {
    bool pass = true;
    ms stack = ms_create(2);
    move m1 = move_create(1, 2, S_ONE, S_ZERO);
    move m2 = ms_top(stack);
    if (m2 != NULL)
        pass = false;
    ms_push(stack, m1);
    if (ms_top_row(stack) != 1 || ms_top_col(stack) != 2 || ms_top_s(stack) != S_ONE || ms_top_p(stack) != S_ZERO)
        pass = false;
    move_delete(m1);
    m1 = NULL;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_pop() {
    bool pass = true;
    ms stack = ms_create(2);
    ms_pop(stack);
    move m1 = move_create(1, 2, S_ONE, S_ZERO);
    move m2 = move_create(3, 4, S_ZERO, S_ONE);
    ms_push(stack, m1);
    ms_push(stack, m2);
    ms_pop(stack);
    if (ms_top_row(stack) != 1 || ms_top_col(stack) != 2 || ms_top_s(stack) != S_ONE || ms_top_p(stack) != S_ZERO)
        pass = false;
    move_delete(m1);
    m1 = NULL;
    move_delete(m2);
    m2 = NULL;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_clear() {
    bool pass = true;
    ms stack = ms_create(2);
    move m1 = move_create(1, 2, S_ONE, S_ZERO);
    move m2 = move_create(3, 4, S_ZERO, S_ONE);
    ms_push(stack, m1);
    ms_push(stack, m2);
    ms_clear(stack);
    if (stack->size != 0 || ms_top(stack) != NULL)
        pass = false;
    move_delete(m1);
    m1 = NULL;
    move_delete(m2);
    m2 = NULL;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_top_row() {
    bool pass = true;
    ms stack = ms_create(2);
    printf("size: %d\n", stack->size);
    if (ms_top_row(stack) != -1)
        pass = false;
    printf("ms_top_row(stack) : %d\n", ms_top_row(stack));
    move m1 = move_create(1, 2, S_ONE, S_ZERO);
    move m2 = move_create(3, 4, S_ZERO, S_ONE);
    ms_push(stack, m1);
    ms_push(stack, m2);
    if (ms_top_row(stack) != 3)
        pass = false;
    ms_pop(stack);
    if (ms_top_row(stack) != 1)
        pass = false;
    move_delete(m1);
    m1 = NULL;
    move_delete(m2);
    m2 = NULL;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_top_col() {
    bool pass = true;
    ms stack = ms_create(2);
    if (ms_top_col(stack) != -1)
        pass = false;
    move m1 = move_create(1, 2, S_ONE, S_ZERO);
    move m2 = move_create(3, 4, S_ZERO, S_ONE);
    ms_push(stack, m1);
    ms_push(stack, m2);
    if (ms_top_col(stack) != 4)
        pass = false;
    ms_pop(stack);
    if (ms_top_col(stack) != 2)
        pass = false;
    move_delete(m1);
    m1 = NULL;
    move_delete(m2);
    m2 = NULL;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_top_s() {
    bool pass = true;
    ms stack = ms_create(2);
    if (ms_top_s(stack) != -2)
        pass = false;
    move m1 = move_create(1, 2, S_ONE, S_ZERO);
    move m2 = move_create(3, 4, S_ZERO, S_ONE);
    ms_push(stack, m1);
    ms_push(stack, m2);
    if (ms_top_s(stack) != S_ZERO)
        pass = false;
    ms_pop(stack);
    if (ms_top_s(stack) != S_ONE)
        pass = false;
    move_delete(m1);
    m1 = NULL;
    move_delete(m2);
    m2 = NULL;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_top_p() {
    bool pass = true;
    ms stack = ms_create(2);
    if (ms_top_p(stack) != -2)
        pass = false;
    move m1 = move_create(1, 2, S_ONE, S_ZERO);
    move m2 = move_create(3, 4, S_ZERO, S_ONE);
    ms_push(stack, m1);
    ms_push(stack, m2);
    if (ms_top_p(stack) != S_ONE)
        pass = false;
    ms_pop(stack);
    if (ms_top_p(stack) != S_ZERO)
        pass = false;
    move_delete(m1);
    m1 = NULL;
    move_delete(m2);
    m2 = NULL;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_is_empty() {
    bool pass = true;
    ms stack = ms_create(2);
    if (!ms_is_empty(stack) && ms_is_empty(NULL))
        pass = false;
    move m1 = move_create(1, 2, S_ONE, S_ZERO);
    ms_push(stack, m1);
    if (ms_is_empty(stack))
        pass = false;
    ms_pop(stack);
    if (!ms_is_empty(stack))
        pass = false;
    move_delete(m1);
    m1 = NULL;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_is_full() {
    bool pass = true;
    ms stack = ms_create(2);
    if (ms_is_full(stack))
        pass = false;
    if (ms_is_full(NULL))
        pass = false;
    move m1 = move_create(1, 2, S_ONE, S_ZERO);
    move m2 = move_create(3, 4, S_ZERO, S_ONE);
    ms_push(stack, m1);
    if (ms_is_full(stack))
        pass = false;
    ms_push(stack, m2);
    if (!ms_is_full(stack))
        pass = false;
    ms_pop(stack);
    if (ms_is_full(stack))
        pass = false;
    move_delete(m1);
    m1 = NULL;
    move_delete(m2);
    m2 = NULL;
    ms_delete(stack);
    stack = NULL;
    return pass;
}

bool test_ms_print() {
    bool pass = true;
    ms stack = ms_create(2);
    move m1 = move_create(1, 2, S_ONE, S_ZERO);
    move m2 = move_create(3, 4, S_ZERO, S_ONE);
    ms_push(stack, m1);
    ms_push(stack, m2);
    ms_print(stack);
    move_delete(m1);
    m1 = NULL;
    move_delete(m2);
    m2 = NULL;
    ms_delete(stack);
    stack = NULL;
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
    if (strcmp("ms_create", argv[1]) == 0)
        pass = test_ms_create();
    else if (strcmp("ms_delete", argv[1]) == 0)
        pass = test_ms_delete();
    else if (strcmp("ms_double_capacity", argv[1]) == 0)
        pass = test_ms_double_capacity();
    else if (strcmp("ms_top", argv[1]) == 0)
        pass = test_ms_top();
    else if (strcmp("ms_push", argv[1]) == 0)
        pass = test_ms_push();
    else if (strcmp("ms_pop", argv[1]) == 0)
        pass = test_ms_pop();
    else if (strcmp("ms_clear", argv[1]) == 0)
        pass = test_ms_clear();
    else if (strcmp("ms_top_row", argv[1]) == 0)
        pass = test_ms_top_row();
    else if (strcmp("ms_top_col", argv[1]) == 0)
        pass = test_ms_top_col();
    else if (strcmp("ms_top_s", argv[1]) == 0)
        pass = test_ms_top_s();
    else if (strcmp("ms_top_p", argv[1]) == 0)
        pass = test_ms_top_p();
    else if (strcmp("ms_is_empty", argv[1]) == 0)
        pass = test_ms_is_empty();
    else if (strcmp("ms_is_full", argv[1]) == 0)
        pass = test_ms_is_full();
    else if (strcmp("ms_print", argv[1]) == 0)
        pass = test_ms_print();
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