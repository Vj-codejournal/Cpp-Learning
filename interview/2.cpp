#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front;
    int back;
    int size;
    int *data;
} Queue;

Queue *createQueue()
{
    Queue *que = (Queue *)malloc(sizeof(Queue));
    que->data = (int *)malloc(5 * sizeof(int));
    que->front = 0;
    que->back = 0;
    que->size = 0;
    return que;
}

void enqueue(Queue *que, int value)
{
    if (que->size == 5)
    {
        printf("Queue is Full\n");
        return;
    }
    que->size++;
    que->data[que->back] = value;
    que->back = (que->back + 1) % 5;
}

int dequeue(Queue *que)
{
    int value;
    if (que->size == 0)
    {
        printf("Queue is Empty\n");
        return -9999;
    }
    que->size--;
    value = que->data[que->front];
    que->front = (que->front + 1) % 5;
    return value;
}

typedef struct Stack
{
    Queue *que1;
    Queue *que2;
    int size;
} Stack;

Stack *createStack()
{
    Stack *stk = (Stack *)malloc(sizeof(Stack));
    stk->que1 = createQueue();
    stk->que2 = createQueue();
    stk->size = 0;
    return stk;
}

void stackPush(Stack *stk, int value)
{
    enqueue(stk->que1, value);
    stk->size +=1;
}

int stackPop(Stack *stk)
{
    int value = 0, s = stk->size;
    while (s > 0)
    {
        value = dequeue(stk->que1);
        if (s > 1)
            enqueue(stk->que2, value);
        s--;
    }
    Queue *temp = stk->que1;
    stk->que1 = stk->que2;
    stk->que2 = temp;
    stk->size -= 1;
    return value;
}

int main()
{
    Stack *stk = createStack();
    stackPush(stk, 1);
    stackPush(stk, 2);
    stackPush(stk, 3);
    printf("Poped out : %d \n", stackPop(stk));
    printf("Poped out : %d \n", stackPop(stk));
    printf("Poped out : %d \n", stackPop(stk));

    return 0;
}