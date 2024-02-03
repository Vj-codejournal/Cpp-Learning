#include <iostream>

using namespace std;
class TwoStack{
    int *arr;
    int top1;
    int top2;
    int size;

    public:
    TwoStack(int size){
        this-> size = size;
        top1= -1;
        top2 = size;
        arr = new int[size];
    }
    //Stack 1
    void push1(int data){
        if(top1 +1 == top2){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top1++;
            arr[top1] = data;
        }
        //or can do
        /*
        if(top2 - top1 >1){
            top++;
            arr[top1] = data;
        }
        else{
            cout<<"stack overflow;"
        }
        */
    }
    //Stack 2
    void push2(int data){
        if(top2 -1 == top1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top2--;
            arr[top2] = data;
        }
        //or can do
        /*
        if(top2 - top1 >1){
            top2--;
            arr[top2] = data;
        }
        else{
            cout<<"stack overflow;"
        }
        */
    }

    int pop1(){
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;

        }
        else{
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
    }
    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;

        }
        else{
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
    }


};
int main(){
    
    return 0;
}