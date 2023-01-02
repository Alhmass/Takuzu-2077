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
        for (uint i = 0; i < stack->size; i++) move_delete(stack->data[i]);
        free(stack->data);
        free(stack);
    }
}

static void ms_double_capacity(ms stack) {
    stack->capacity *= 2;
    stack->data = realloc(stack->data, sizeof(move) * stack->capacity);
    test_pointer(stack->data, "ms_double_capacity: realloc failed");
}

move ms_top(ms stack) {
    if (ms_is_empty(stack))
        return NULL;
    return stack->data[stack->size - 1];
}
void ms_push(ms stack, move m) {
    if (ms_is_full(stack))
        ms_double_capacity(stack);
    move new = move_create(move_row(m), move_col(m), move_s(m), move_p(m));
    stack->data[stack->size] = new;
    stack->size++;
}
void ms_pop(ms stack) {
    if (ms_is_empty(stack))
        return;
    move_delete(ms_top(stack));
    stack->size--;
}
void ms_clear(ms stack) {
    while (!ms_is_empty(stack)) ms_pop(stack);
}

uint ms_top_row(ms stack) {
    if (ms_is_empty(stack))
        return -1;
    return move_row(ms_top(stack));
}
uint ms_top_col(ms stack) {
    if (ms_is_empty(stack))
        return -1;
    return move_col(ms_top(stack));
}
square ms_top_s(ms stack) {
    if (ms_is_empty(stack))
        return -1;
    return move_s(ms_top(stack));
}
square ms_top_p(ms stack) {
    if (ms_is_empty(stack))
        return -1;
    return move_p(ms_top(stack));
}

bool ms_is_empty(ms stack) {
    if (stack == NULL)
        return true;
    return stack->size == 0;
}
bool ms_is_full(ms stack) {
    if (stack == NULL)
        return false;
    return stack->size == stack->capacity;
}

void ms_print(ms stack) {
    printf("move_stack: size=%d, capacity=%d\n", stack->size, stack->capacity);
    for (uint i = 0; i < stack->size; i++) {
        printf("[%d] [%d] [%d] [%d]\n", move_row(stack->data[i]), move_col(stack->data[i]), move_s(stack->data[i]),
               move_p(stack->data[i]));
    }
}