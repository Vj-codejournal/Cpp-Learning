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

    void full(){
        static int count =1;
        int *arr2;
        if(top  == size -1 && count%2 != 0){
            size = 2*size;
            arr2 = new int[size];
            arr2 = arr;
            delete arr;
            count++;
        }
        else if(top  == size -1 && count%2 == 0){
            size = 2*size;
            int *arr = new int[size];
            arr = arr2;
            delete arr2;
            count++;
        }
    }
};
int main(){
    Stack st(5);

    // st.push(22);
    // st.push(43);
    
    // st.push(44);
    // st.push(45);

    // cout<<st.peek()<<endl;
    // st.pop();
    for(int i = 0;i<25;i++){
        st.push(i);

        st.full();
    }
    cout<<st.peek();
    return 0;
}


//Yathansh Method

#include <stdio.h>
#include <stdlib.h>
int f=-1,r=-1;
void pop(int arr[]){
    if(f==-1||f>r){
        printf("Underflow");
        return;
    }
    printf("Deleting the element %d ",arr[f]);
    f++;
}
void display(int arr[]){
    for(int i=f;i<=r;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int *arr=(int *) malloc (5 * sizeof (int));
    int n;
    do{
    printf("Enter your choice:\n1-Entering the elements in the stack\n2-Clearing the stack\n3-Displaying the stack\n4-Exit\n");
    scanf("%d",&n);
    switch(n){
        case 1:
    {int x=0;
    do{
        printf("Enter your element.Press -1 to terminate : ");
        scanf("%d",&x);
        if(x!=-1){
            r++;
            if(f==-1)
            f=0;
            if(r==(sizeof(arr)/sizeof(int))){
            int *q = (int *) malloc ((2*(sizeof(arr)/sizeof(int))) * sizeof (int));
    for (int i = 0; i <(sizeof(arr)/sizeof(int)); i++)
    {
        q[i] = arr[i];
    }
    free (arr);
    arr= q;}
    arr[r]=x;
        }
    }while(x!=-1);
    break;}
    
    case 2:{
        pop(arr);
        break;
    }
    case 3:{
        display(arr);
        break;
    }
    }
    }while(n!=4);
    return 0;
}