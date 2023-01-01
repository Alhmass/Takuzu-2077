#include "move_stack.h"

static void throw_error(char *msg) {
    fprintf(stderr, "[error] %s\n", msg);
    exit(EXIT_FAILURE);
}
static void test_pointer(void *p, char *msg) {
    if (p == NULL)
        throw_error(msg);
}

ms ms_create(uint capacity) {
    ms stack = malloc(sizeof(struct move_stack_s));
    test_pointer(stack, "ms_create: stack malloc failed");
    stack->data = malloc(sizeof(move) * capacity);
    test_pointer(stack->data, "ms_create: data malloc failed");
    stack->size = 0;
    stack->capacity = capacity;
    return stack;
}
void ms_delete(ms stack) {
    if (stack != NULL) {
        for (uint i = 0; i < stack->size; i++)
            move_delete(stack->data[i]);
        free(stack->data);
        free(stack);
    }
}

static ms ms_double_capacity(ms stack) {
    stack->capacity *= 2;
    stack->data = realloc(stack->data, sizeof(move) * stack->capacity);
    test_pointer(stack->data, "ms_double_capacity: realloc failed");
    return stack;
}

move ms_top(ms stack) {
    if (ms_is_empty(stack))
        return NULL;
    return stack->data[stack->size - 1];
}

ms ms_push(ms stack, move m) {
    if (ms_is_full(stack))
        stack = ms_double_capacity(stack);
    stack->data[stack->size] = m;
    stack->size++;
    return stack;
}

ms ms_pop(ms stack) {
    if (ms_is_empty(stack))
        return stack;
    stack->size--;
    move_delete(stack->data[stack->size]);
    return stack;
}

ms ms_clear(ms stack) {
    while (!ms_is_empty(stack))
        stack = ms_pop(stack);
    return stack;
}

bool ms_is_empty(ms stack) {
    return stack->size == 0;
}

bool ms_is_full(ms stack) {
    return stack->size == stack->capacity;
}