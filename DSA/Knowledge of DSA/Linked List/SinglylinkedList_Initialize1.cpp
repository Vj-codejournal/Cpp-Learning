#include <iostream>

using namespace std;
struct node{
    int data;
    node * link;
};
int main(){
    //for first element of list
    node *head = nullptr;

    head = new node();
    head->data =45;
    head-> link = nullptr;

    //add 2nd element
    node * temp = new node();

    temp->data =98;
    temp->link = nullptr;
    head->link = temp;

    //add 3rd element
    temp = new node();//reuse the temp ptr
    temp->data=3;
    temp->link = nullptr;
    //method 1
    //head->link->link = temp;
    //method 2
    node * temp2;
    temp2 =head;
    while(temp2 != nullptr){
        temp2= temp2->link;
    }
    temp2->link = temp; 
    return 0;
}


