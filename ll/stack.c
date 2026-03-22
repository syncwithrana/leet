#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  { 
    int *arr;
    int capacity;
    int top;
} stack_type;

stack_type* stack_create(int capacity)    {
    stack_type *stack = (stack_type *)malloc(sizeof(stack_type));
    stack->capacity = capacity;
    stack->arr = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    return stack;
}

void stack_push(stack_type *stack, int x)  {
    if (stack->top == stack->capacity - 1)  {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = x;
}

int stack_pop(stack_type *stack)   {
    if (stack->top == -1)   {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int stack_peek(stack_type *stack)    {
    if (stack->top == -1)   {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

bool stack_isempty(stack_type *stack)  {
    return stack->top == -1;
}

bool stack_isfull(stack_type *stack)   {
    return stack->top == stack->capacity - 1;
}

void stack_free(stack_type *stack)    {
    free(stack->arr);
    free(stack);
}

int main()  {
    stack_type *st = stack_create(4);

    stack_push(st, 1);
    stack_push(st, 2);
    stack_push(st, 3);
    stack_push(st, 4);

    printf("Popped: %d\n", stack_pop(st));
    printf("Top element: %d\n", stack_peek(st));
    printf("Is stack empty: %s\n", stack_isempty(st) ? "Yes" : "No");
    printf("Is stack full: %s\n", stack_isfull(st) ? "Yes" : "No");
    stack_free(st);
    return 0;
} 