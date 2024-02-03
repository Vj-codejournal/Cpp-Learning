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

    int count = 0;
void segregateEvenOdd()
{ 
	node *end = head;
	node *prev = NULL;
    node *curr = head;

	
	while (end->next != NULL)
		end = end->next;

	node *new_end = end;

	
	while (curr->data % 2 != 0 && curr != end)
	{
		new_end->next = curr;
		curr = curr->next;
		new_end->next->next = NULL;
		new_end = new_end->next;
	}

	
	if (curr->data%2 == 0)
	{
		
		head = curr;

		
		while (curr != end)
		{
			if ( (curr->data) % 2 == 0 )
			{
				prev = curr;
				curr = curr->next;
			}
			else
			{
				
				prev->next = curr->next;

				
				curr->next = NULL;

				
				new_end->next = curr;

				
				new_end = curr;

				
				curr = prev->next;
			}
		}
	}

	
	else prev = curr;

	
	if (new_end != end && (end->data) % 2 != 0)
	{
		prev->next = end->next;
		end->next = NULL;
		new_end->next = end;
	}
	return;
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

    ll.segregateEvenOdd();

    ll.print();

    
    

    return 0;
}