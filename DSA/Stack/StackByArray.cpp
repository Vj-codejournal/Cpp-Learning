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
            cout<<arr[top]<<endl;
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
int main(){
    Stack st(5);

    st.push(22);
    st.push(43);
    
    st.push(44);
    st.push(45);

    cout<<st.peek()<<endl;
    st.pop();
 
    return 0;
}