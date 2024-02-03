#include <iostream>

using namespace std;
class node{
    public:
    int data;
    node *next;
    node(){
        data = 0;
        next =nullptr;

    }
    node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList{
    node *head;
    public:
    LinkedList(){head = nullptr;}
    
    void insertNode(int data){
        node * newNode = new node(data);
        if(head == nullptr){
            head = newNode;
            return;
        }

        node *temp = head;

        while(temp->next != nullptr){

            temp = temp->next;
        }

        temp->next =newNode;
    }
    void addNode(int newData,int pos){
        node * newNode = new node(newData);
        int count = 1;
        node *temp = head;
        while(temp->next != nullptr){
            count++;
            if(count == pos){
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
            
        }
        
        
    }

     void print()
    {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};



int main()
{   int n,a;
    cin>>n;
    LinkedList ll;
    for(int i = 0;i<n;i++){
        cin>>a;
        ll.insertNode(a);
    }
    int x;
    cout<<"What node would like to add: ";
    cin>>x;
    int y = ((n/2) + 2);
    ll.addNode(x,y);
    ll.print();




    
    return 0;
}