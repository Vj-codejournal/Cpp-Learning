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
            exit(1);
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

void compare(Stack &s1,Stack &s2){
    while(!s1.isEmpty() && !s2.isEmpty()){
    if(s1.peek() == s2.peek()){
        s1.pop();
        s2.pop();
    }
    else{
        cout<<"Stacks not Identical";
        break;
    }
    }
    cout<<"Stacks Identical";
}
 

int main()
{
    
    Stack s1;
    Stack s2;
    s1.push(11);
    s1.push(22);
    s1.push(33);
    s1.push(44);


    s2.push(11);
    s2.push(22);
    s2.push(33);
    s2.push(44);

    compare(s1,s2);
 
 
    
    
    
    
 
    return 0;
}