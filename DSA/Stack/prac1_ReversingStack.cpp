#include <bits/stdc++.h>
using namespace std;
 

class Node {
public:
    int data;
    Node* link;
    Node(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};
 
class Stack {
    Node* top;
 
public:
    Stack() { top = NULL; }
 
    void push(int data)
    {
 
        
        Node* temp = new Node(data);
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }
 
        
        //temp->data = data;
 
        
        temp->link = top;
        top = temp;
    }
 
    
    bool isEmpty()
    {
        return top == NULL;
    }
 
    
    int peek()
    {
        if (!isEmpty())
            return top->data;
        else
            cout<<"stack is empty\n";
            return;
    }
 
    
    void pop()
    {
        Node* temp;
 
        
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            return;
        }
        else {
 
            temp = top;
            top = top->link;
            
            free(temp);
        }
    }
 
    
    
};
 

int main()
{
    
    Stack s, stemp;
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
 
    while(!s.isEmpty()){
        stemp.push(s.peek());
        s.pop();
    }
    while(!stemp.isEmpty()){
        s.push(stemp.peek());
        stemp.pop();
    }
    cout<<"Reversed stack\n";
    
    
    while(!s.isEmpty()){
        cout<<s.peek()<<endl;
        s.pop();
    }
    
    
 
    return 0;
}


//using recursion

#include <bits/stdc++.h> 
using namespace std;


void pushAtBottom(stack<int>& myStack, int x) 
{
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();
    pushAtBottom(myStack,x);
    myStack.push(num);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);

    pushAtBottom(stack,num);

}

int main(){
    stack<int> inputStack;
    int n;
    
    int t;
    cin>>t;

    while(t-->0){
        cin>>n;
        int a;
        for(int i = 0;i<n;i++){
            cin>>a;
            inputStack.push(a);

        }

        reverseStack(inputStack);

    }
}