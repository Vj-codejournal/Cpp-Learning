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

    bool enqueue(int value){
        if((front == 0 && rear == size -1) || (rear == (front -1)%(size-1))){
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
    // bool enqueue(int value){
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

    int dequeue(){
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
    // int dequeue(){
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

    void full(){
        static int count =1;
        int *arr2;
        if(((front == 0 && rear == size -1) || (rear == (front -1)%(size-1))) && count%2 != 0){
            size = 2*size;
            arr2 = new int[size];
            arr2 = arr;
            delete arr;
            count++;
        }
        else if(((front == 0 && rear == size -1) || (rear == (front -1)%(size-1))) && count%2 == 0){
            size = 2*size;
            int *arr = new int[size];
            arr = arr2;
            delete arr2;
            count++;
        }
    }




};
int main(){

    CircularQueue q(5);
    for(int i = 0;i<6;i++){
        q.enqueue(i);
        q.full();
    }
    //cout<<q.front();
    for(int i = 0;i<6;i++){
        cout<<q.dequeue()<<endl;
    }
    return 0;
}