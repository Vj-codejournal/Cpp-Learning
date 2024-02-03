#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int size;
} Stack;

Stack* createStack(int size) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->arr = (int*) malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

void push(Stack* stack, int data) {
    if (stack->top == stack->size - 1) {
        printf("Stack Overflow\n");
    } else {
        stack->top++;
        stack->arr[stack->top] = data;
    }
}

void pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack->arr[stack->top]);
        stack->top--;
    }
}

int peek(Stack* stack) {
    if (stack->top >= 0) {
        return stack->arr[stack->top];
    } else {
        printf("Stack is Empty\n");
        return -1;
    }
}

int isEmpty(Stack* stack) {
    if (stack->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Stack* st = createStack(5);
    push(st, 22);
    push(st, 43);
    push(st, 44);
    push(st, 45);
    printf("%d\n", peek(st));
    return 0;
}