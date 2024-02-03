#include <bits/stdc++.h>
using namespace std;
 

class Node {
public:
    int data;
    Node* link;
    Node(int data)
    {
        this->data = data;
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
 
        cout<<"Inserted "<<temp->data<<endl;
        temp->link = top;
        top = temp;
    }
 
    
    bool isEmpty()
    {
        return top == NULL;
    }
 
    
    void peek()
    {
        if (!isEmpty())
            cout<<top->data;
        else
            cout<<"stack is empty\n";
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
            cout<<"Deleted "<<temp->data<<endl;
            top = top->link;
            
            free(temp);
        }
    }
 
    
    
};
 

int main()
{
    
    Stack s;
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
 
 
    
    cout << "\nTop element is ";
    s.peek();
    cout<< endl;
 
    s.pop();
    s.pop();
 
    cout << "\nTop element is ";
    s.peek();
    cout<< endl;
    
    
 
    return 0;
}