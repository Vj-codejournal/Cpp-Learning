#include <iostream>

using namespace std;
class Stack{
    public:
    int *arr;
    int top;
    int size;

    //constructor
    Stack(int size){
        this-> size = size;
        arr = new int [size];
        top = -1;

    }

    void push(int data){
        if(top == size - 1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top++;
            arr[top] = data;
        }
        //or can do
        /*
        if(size - top >1){
            top++;
            arr[top] = data;
        }
        else{
            cout<<"stack overflow;"
        }
        */
    }
    void pop(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            
            top--;
        }
        //or can do
        /*
        if(top>=0){
            cout<<arr[top];
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
        */
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }

    }
    bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
    }
};

class Queue{
    Stack s1 = Stack(10); //to use parametrized constrictor of another class in any other place except main have to do this 
    Stack s2 = Stack(10);

    public:

    void enqueue(int data){
        while(!s2.isEmpty()){
            s1.push(s2.peek());
            s2.pop();
        }

        s1.push(data);
    }

    void dequeue(){
        while(!s1.isEmpty()){
            s2.push(s1.peek());
            s1.pop();
        }
        s2.pop();
    }

    void front(){
        if(s2.isEmpty()){
            while(!s1.isEmpty()){
            s2.push(s1.peek());
            s1.pop();
        }
        cout<<s2.peek();
        while(!s2.isEmpty()){
            s1.push(s2.peek());
            s2.pop();
        }
        }
        else{
            cout<<s2.peek();
        }
    }

    bool isEmpty(){
        if(s1.isEmpty() && s2.isEmpty()){
            return true;
        }
        return false;
    }

};
int main(){
    Queue q;
    q.enqueue(11);
    q.enqueue(22);
    q.enqueue(33);
    q.enqueue(44);
 
 
    
    cout << "\nfront element is ";
    q.front();
    cout<< endl;
 
    q.dequeue();
    q.dequeue();

    cout << "\nfront element is ";
    q.front();
    cout<< endl;
 
    return 0;
}