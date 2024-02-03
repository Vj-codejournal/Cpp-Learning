#include <iostream>

using namespace std;
class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;

    public:

    CircularQueue(int size){
        this-> size = size;
        arr = new int [size];
        front = -1;
        rear = -1;

    }

    bool push_rear(int value){//normally enqueue use rear1
        if((front == 0 && rear == size -1) || (front != 0 && rear == (front -1)%(size-1))){
            cout<<"Queue is full";
            return false;
        }
        else if(front  == -1){//first element to push
            front = rear = 0;
            arr[rear] = value;
        }
        else if(rear == size -1 && front != 0){
            rear = 0;
            arr[rear] = value;
        }
        else{//normal case
            rear++;
            arr[rear] = value;
        }
        return true;
    }
    //class
    // bool push_back(int value){
    //     if((front == 0 && rear == size -1) || (rear + 1 == front)){
    //         cout<<"Queue is full";
    //         return false;
    //     }
    //     else {
    //         if(front == -1) front =0;

    //         rear = (rear + 1)%size;
    //         arr[rear] = value;
    //     }
    //     return true;
    // }

    int pop_front(){//normally dequeue use front1
        if(front ==-1){
            cout<<"Queue is Empty"<<endl;

        }
        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){
            front = rear = -1;
        }
        else if( front == size - 1 ){
            front =0;
        }
        else{
            front++;
        }
        return ans;

    }

    
    //class method
    // int pop_front(){
    //     int ans;
    //     if(front ==-1){
    //         cout<<"Queue is Empty"<<endl;

    //     }
    //     else{
    //     ans = arr[front];
    //     arr[front] = -1;
    //     if(front == rear){
    //         front = rear = -1;
    //     }
    //     else{
    //         front  = (front + 1)% size;
    //     }
        
    //     }
    // return ans;

    // }

    bool push_front(int data){
        //check full same as before
        if((front == 0 && rear == size -1) || (front != 0 &&rear == (front -1)%(size-1))){
            cout<<"Queue is full";
            return false;
        }
        else if(front  == -1 ){//rear should not be at max-1 for front to insert there
            front = rear = 0;
        }
        else if(front == 0 && rear != size -1){
            front = size-1;
        }
        else{
            front--;
        }

        arr[front] = data;
        return true;


    }
    
    int pop_rear(){
         if(front ==-1){//same as before
            cout<<"Queue is Empty"<<endl;
            return -1;

        }
        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){
            front = rear = -1;
        }
        else if( rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }
        return ans;

    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        else false;
    }

    bool isFull(){
        if((front == 0 && rear == size -1) || (front != 0 && rear == (front -1)%(size-1))){//as front -1 cause problem ///////////check why didnt cause problem in previous codes
            
            return true;
        }
        return false;
    }


};
int main(){
    CircularQueue q(10);
    q.push_front(5);
    q.push_front(6);
    q.push_rear(2);
    q.push_rear(1);
    cout<<"Pop Front "<<q.pop_front()<<endl;
    cout<<"Pop Front "<<q.pop_front()<<endl;
    cout<<"Pop Back "<<q.pop_rear()<<endl;
    cout<<"Pop Back "<<q.pop_rear();
    return 0;
}