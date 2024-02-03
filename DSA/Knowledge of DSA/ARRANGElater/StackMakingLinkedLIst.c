#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* stack, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("\nStack Overflow");
        exit(1);
    }

    printf("Inserted %d\n", data);
    temp->data = data;
    temp->link = stack->top;
    stack->top = temp;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == NULL;
}

void peek(struct Stack* stack)
{
    if (!isEmpty(stack))
        printf("%d", stack->top->data);
    else
        printf("stack is empty\n");
}

void pop(struct Stack* stack)
{
    struct Node* temp;
    if (stack->top == NULL) {
        printf("\nStack Underflow\n");
        return;
    }
    else {
        temp = stack->top;
        printf("Deleted %d\n", temp->data);
        stack->top = stack->top->link;
        free(temp);
    }
}

int main()
{
    struct Stack s;
    s.top = NULL;
    push(&s, 11);
    push(&s, 22);
    push(&s, 33);
    push(&s, 44);
    printf("\nTop element is ");
    peek(&s);
    printf("\n");
    pop(&s);
    pop(&s);
    printf("\nTop element is ");
    peek(&s);
    printf("\n");
    return 0;
}