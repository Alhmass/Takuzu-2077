#include "move_stack.h"

static void throw_error(char *msg) {
    fprintf(stderr, "[error] %s\n", msg);
    exit(EXIT_FAILURE);
}
static void test_pointer(void *p, char *msg) {
    if (p == NULL)
        throw_error(msg);
}

moves ms_create(uint capacity) {
    moves stack = malloc(sizeof(struct move_stack_s));
    test_pointer(stack, "ms_create: stack malloc failed");
    stack->capacity = capacity;
    stack->size = 0;
    stack->data = malloc(sizeof(move) * capacity);
    test_pointer(stack->data, "ms_create: data malloc failed");
    return stack;
}

void ms_delete(moves stack) {
    if (stack != NULL) {
        for (uint i = 0; i < stack->size; i++)
            move_delete(stack->data[i]);
        free(stack->data);
        free(stack);
    }
}

moves ms_double_capacity(moves stack) {
    stack->capacity *= 2;
    stack->data = realloc(stack->data, sizeof(move) * stack->capacity);
    test_pointer(stack->data, "ms_double_capacity: realloc failed");
    return stack;
}

move ms_top(moves stack) {
    if (stack->size == 0)
        return NULL;
    return stack->data[stack->size - 1];
}

moves ms_push(moves stack, move m) {
    if (stack->size == stack->capacity)
        stack = ms_double_capacity(stack);
    stack->data[stack->size] = m;
    stack->size++;
    return stack;
}

moves ms_pop(moves stack) {
    if (stack->size != 0)
        stack->size--;
    return stack;
}

moves ms_clear(moves stack) {
    stack->size = 0;
    return stack;
}

bool ms_is_empty(moves stack) {
    return stack->size == 0;
}

bool ms_is_full(moves stack) {
    return stack->size == stack->capacity;
}