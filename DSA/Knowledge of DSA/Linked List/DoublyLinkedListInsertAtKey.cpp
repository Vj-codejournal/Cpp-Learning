#include <iostream>

using namespace std;
class node{
    public:
    int data;
    node *next;
    node *prev;
    node(){
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
    node(int data){
        this ->data = data;
        this ->next = nullptr;
        this ->prev = nullptr;
    }
};
class linkedlist{
    node* head;
    public:
    linkedlist(){head = nullptr;}

    void insertBeforeKey(int key,int data1){
        if(head == nullptr){
        cout<<"List is empty\n";
        return;
        }
        else{
        node *newNode = new node(data1);
        if(head->next == nullptr || head -> data == key){
            newNode->next =head;
            head->prev = newNode;
            head = newNode;

        }
        else{
            node *temp = head;
            temp = temp-> next;//as head insertion we have covered 
            while(temp != nullptr){
                if(temp->data == key){
                    newNode->prev = temp->prev;
                    newNode->next = temp;
                    temp->prev->next = newNode;
                    temp->prev = newNode;

                    break;
                }
                else if(temp->next == nullptr){
                    cout<<"Key not present in list\n";
                    break;
                }

                temp = temp->next;
            }
        }
        }
    }

    void insertNode(int data)
    {
        
        node* newNode = new node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        node* temp = head;
        while (temp->next != NULL) {

            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }


    void printList()
    {
        node* temp = head;

        
        if (head == NULL) {
            cout << "List empty\n" << endl;
            return;
        }

        
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
            
        }
        cout<<endl;
    }
};
int main(){
    linkedlist l;
    int choice;
    do{
        
        cout<<"Enter your choice\n";
        cout<<"1. Insert at End\n2. Insert at Key\n3. Print List\n4. Exit\n";
        cin>>choice;
        int data,key;
        switch(choice){

            case 1:
            cout<<"Enter the data\n";
            cin>>data;
            l.insertNode(data);
            break;
            case 2:
            cout<<"Enter the key and the data to be inserted before it\n";
            cin>>key>>data;
            l.insertBeforeKey(key,data);
            break;
            case 3:
            l.printList();
            break;
            case 4:
            break;
            default:
            cout<<"invalid choice\n";

        }

    }while(choice != 4);
    return 0;
}