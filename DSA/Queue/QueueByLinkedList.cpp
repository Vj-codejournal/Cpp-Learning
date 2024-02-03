#include <bits/stdc++.h>
using namespace std;
 

class Node {
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
 
class Queue {
    Node *head,*tail;//if dont want two ptrs use circular linked list

 
public:
    Queue() { head = nullptr;tail = nullptr; }
 
    void enqueue(int data)
    {
 
        
        Node* newnode = new Node(data);
        if (!newnode) {
            cout << "\nQueue full";
            exit(1);
        }
 
        
        //temp->data = data;
 
        cout<<"Inserted "<<newnode->data<<endl;
        if(head == nullptr){
            head = newnode;
            tail = newnode;
            return;
        }

        tail->next = newnode;
        tail = newnode;

    }
 
    
    bool isEmpty()
    {
        return head == NULL;
    }
 
    
    void front()
    {
        if (!isEmpty())
            cout<<head->data;
        else
            cout<<"queue is empty\n";
    }
 
    
    void dequeue()
    {
        Node* temp;
 
        
        if (head == NULL) {
            cout << "\nQueue Underflow" << endl;
            return;
        }
        else {
            temp = head;
            cout<<"Deleted "<<temp->data<<endl;
            head = head->next;
            
            free (temp);
        }
    }
 
    
    
};
 

int main()
{
    
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