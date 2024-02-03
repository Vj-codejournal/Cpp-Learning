#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct Queue
{
    int front;
    int back;
    int size;
    int capacity;
    int *data;
} Queue;

Queue *createQueue(int cap)
{
    Queue *que = (Queue *)malloc(sizeof(Queue));
    que->data = (int *)malloc(cap * sizeof(int));
    que->front = 0;
    que->back = 0;
    que->size = 0;
    que->capacity = cap;
    return que;
}

void increase_capacity(Queue *que)
{
    int n = (que->capacity) * 2;
    realloc(que->data, n);
    que->capacity = n;
}

void enqueue(Queue *que, int value)
{
    if (que->size == que->capacity)
    {
        increase_capacity(que);
    }
    que->size++;
    que->data[que->back] = value;
    que->back++;
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
    que->front++;
    return value;
}

void dispaly(Queue *que)
{
    cout << "Queue Capacity : " << que->capacity << endl
         << "The Queue is : ";
    int k = que->front;
    while (k != que->size)
    {
        cout << que->data[k] << " ";
        k++;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter Capacity of Queue : ";
    cin >> n;
    Queue *que = createQueue(n);
    enqueue(que, 1);
    enqueue(que, 2);
    enqueue(que, 3);
    enqueue(que, 4);
    dispaly(que);
    enqueue(que, 5);
    enqueue(que, 6);
    enqueue(que, 7);
    enqueue(que, 8);
    enqueue(que, 9);
    enqueue(que, 10);
    dispaly(que);

    cout << "Dequed : " << dequeue(que) << endl;
    cout << "Dequed : " << dequeue(que) << endl;
    cout << "Dequed : " << dequeue(que) << endl;
    cout << "Dequed : " << dequeue(que) << endl;
    cout << "Dequed : " << dequeue(que) << endl;

    cout << "Dequed : " << dequeue(que) << endl;
    cout << "Dequed : " << dequeue(que) << endl;
    cout << "Dequed : " << dequeue(que) << endl;
    cout << "Dequed : " << dequeue(que) << endl;
    cout << "Dequed : " << dequeue(que) << endl;

    return 0;
}