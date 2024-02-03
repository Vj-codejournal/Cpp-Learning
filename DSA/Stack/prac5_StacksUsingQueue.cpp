//Costly PUSH

#include <iostream>

using namespace std;
class Queue{
    int *arr;
    int qfront;
    int rear;
    int size;

    public:
    // Queue(){
    //      arr = new int [5];
    //      qfront = 0;
    //     rear = 0;

    // }
    Queue(int size){
        this-> size = size;
        arr = new int [size];
        qfront = 0;
        rear = 0;

    }


    void push(int data){
        if(rear == size){
            cout<<"Queue is Full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }

    }

    int pop(){
        if(qfront == rear){
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront == 0;
                rear == 0;
            }
            return ans;
        }
    }

    int front(){
        if(qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }

    bool isEmpty(){
        if(qfront == rear){
            return true;
        }
        else{
            return false;
        }
    }
};
class Stack{
	
    Queue q1=Queue(10);
	Queue q2=Queue(10);

public:
	void push(int x)
	{
		
		q2.push(x);

		
		while (!q1.isEmpty()) {
			q2.push(q1.front());
			q1.pop();
		}

		
		Queue q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{
		
		if (q1.isEmpty())
			return;
		q1.pop();
	}

	int top()
	{
		if (q1.isEmpty())
			return -1;
		return q1.front();
	}

	
};
int main()
{   
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
    s.pop();
	
	return 0;
}


// MY Costly POP


#include <iostream>

using namespace std;
class Queue{
    int *arr;
    int qfront;
    int rear;
    int size;

    public:
    // Queue(){
    //      arr = new int [5];
    //      qfront = 0;
    //     rear = 0;

    // }
    Queue(int size){
        this-> size = size;
        arr = new int [size];
        qfront = 0;
        rear = 0;

    }


    void push(int data){
        if(rear == size){
            cout<<"Queue is Full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }

    }

    int pop(){
        if(qfront == rear){
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront == 0;
                rear == 0;
            }
            return ans;
        }
    }

    int front(){
        if(qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }

    bool isEmpty(){
        if(qfront == rear){
            return true;
        }
        else{
            return false;
        }
    }
    bool onebefore(){
        if(qfront == rear -1){
            return true;
        }
        return false;
    }
};
class Stack{
	
    Queue q1=Queue(10);
	Queue q2=Queue(10);

public:
	void push(int x)
	{
		q1.push(x);
		
	}

	void pop()
	{
		while(!q1.onebefore()){
            q2.push(q1.front());
            q1.pop();

        }
        cout<<q1.front()<<endl;
        q1.pop();
        q1 =  q2;
        Queue q=Queue(10);
        q2 = q;

		
	}

	int top()
	{
		if (q1.isEmpty())
			return -1;
		return q1.front();
	}

	
};
int main()
{   
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	
	//cout << s.top() << endl;
	s.pop();
	//cout << s.top() << endl;
	s.pop();
	//cout << s.top() << endl;
    s.pop();
	
	return 0;
}









// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Queue
// {
//     int front;
//     int back;
//     int size;
//     int *data;
// } Queue;

// Queue *createQueue()
// {
//     Queue *que = (Queue *)malloc(sizeof(Queue));
//     que->data = (int *)malloc(5 * sizeof(int));
//     que->front = 0;
//     que->back = 0;
//     que->size = 0;
//     return que;
// }

// void enqueue(Queue *que, int value)
// {
//     if (que->size == 5)
//     {
//         printf("Queue is Full\n");
//         return;
//     }
//     que->size++;
//     que->data[que->back] = value;
//     que->back = (que->back + 1) % 5;
// }

// int dequeue(Queue *que)
// {
//     int value;
//     if (que->size == 0)
//     {
//         printf("Queue is Empty\n");
//         return -9999;
//     }
//     que->size--;
//     value = que->data[que->front];
//     que->front = (que->front + 1) % 5;
//     return value;
// }

// typedef struct Stack
// {
//     Queue *que1;
//     Queue *que2;
//     int size;
// } Stack;

// Stack *createStack()
// {
//     Stack *stk = (Stack *)malloc(sizeof(Stack));
//     stk->que1 = createQueue();
//     stk->que2 = createQueue();
//     stk->size = 0;
//     return stk;
// }

// void stackPush(Stack *stk, int value)
// {
//     enqueue(stk->que1, value);
//     stk->size +=1;
// }

// int stackPop(Stack *stk)
// {
//     int value = 0, s = stk->size;
//     while (s > 0)
//     {
//         value = dequeue(stk->que1);
//         if (s > 1)
//             enqueue(stk->que2, value);
//         s--;
//     }
//     Queue *temp = stk->que1;
//     stk->que1 = stk->que2;
//     stk->que2 = temp;
//     stk->size -= 1;
//     return value;
// }

// int main()
// {
//     Stack *stk = createStack();
//     stackPush(stk, 1);
//     stackPush(stk, 2);
//     stackPush(stk, 3);
//     printf("Poped out : %d \n", stackPop(stk));
//     printf("Poped out : %d \n", stackPop(stk));
//     printf("Poped out : %d \n", stackPop(stk));

//     return 0;
// }