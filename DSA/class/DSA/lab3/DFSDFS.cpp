#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int data)
    {
        this->value = data;
        this->next = NULL;
    }
    ~Node()
    {
        int data = this->value;
        if (this->next == NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Dequed : " << value << endl;
    }
};

class Queue
{
    Node *tail;

public:
    Queue()
    {
        tail = NULL;
    }
    void enqueue(int element)
    {
        Node *newNode = new Node(element);
        if (tail == NULL)
        {
            tail = newNode;
            tail->next = tail;
			//cout<<"done";
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail=newNode;
		//cout<<"done";
        return;
    }
    void dequeue()
    {	int value;
        
        if(tail ==NULL)
        {
            cout<<"Queue Underflow"<<endl;
            return;
        }
		if(tail->next == tail){
			value = tail->value;
			cout << "Dequed : " << value << endl;
			tail = NULL;
			return;
		}
        Node *temp = tail-> next;
        tail->next = temp -> next;
        delete temp;
        //temp -> next = NULL;
    }
};

int main()
{
    Queue q;
    q.dequeue();
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    // q.dequeue();
}