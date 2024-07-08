// class Node{
//     public:
//     int val;
//     Node* next;

//     Node(){
//         val = 0;
//         next = nullptr;
//     }
//     Node(int val){
//         this->val = val;
//         this->next = nullptr;
//     }
// };

// class MyLinkedList {
    
// public:
//     Node* head;
//     MyLinkedList() {
//         head = nullptr;  
//     }
//     bool lencheck(int index){
//         int length = 0;

//         Node* temp = head;

//         while(temp != nullptr){
//             temp = temp->next;
//             length++;
//         }

//         if(index<=length-1){
//             return true;
//         }
//         return false;
//     }
//     bool lencheck2(int index){
//         int length = 0;

//         Node* temp = head;

//         while(temp != nullptr){
//             temp = temp->next;
//             length++;
//         }
//         length++;

//         if(index<=length-1){
//             return true;
//         }
//         return false;
//     }
//     int get(int index) {
//         if(lencheck(index)){
//             int count = 0;
//             Node* temp = head;

//             while(count != index){
//                 temp = temp->next;
//                 count++;
//             }

//             return temp->val;
//         }
//         else{
//             return -1;
//         }
//     }
    
//     void addAtHead(int val) {
//         Node* newNode = new Node(val);
//         if(head = nullptr){
//             head = newNode;
//             return;
//         }

//         newNode->next = head;
//         head = newNode;
//     }
    
//     void addAtTail(int val) {
//         Node* newNode = new Node(val);
//         if(head == nullptr){
//             head = newNode;
//             return;
//         }

//         Node* temp = head;

//         while(temp->next != nullptr){
//             temp = temp->next;

//         }
//         temp->next = newNode;
//     }
//     //can use add at index for head and tail also
//     void addAtIndex(int index, int val) {
//         if(lencheck2(index)){
//             if(index == 0){
//                 addAtHead(val);
//                 return;
//             }
//             int count = 0;
//             Node* temp = head;
//             Node* ttemp = head;
//             while(count != index){
//                 temp = temp->next;
//                 count++;
//             }//can stop count != index - 1 so stop at one before index
//             //ttemp start after count become 1 so stay one behind

//             while(ttemp->next != temp){
//                 ttemp = ttemp->next;
//             }

//             Node* newNode = new Node(val);

//             ttemp->next = newNode;
//             newNode->next  = temp;
//         }
//     }
    
//     void deleteAtIndex(int index) {
//         if(lencheck(index)){
//             if(index ==0){
//                 head = nullptr;
//                 return;
//             }
//             int count = 0;
//             Node* temp = head;
//             Node* ttemp = head;
//             while(count != index){
//                 temp = temp->next;
//                 count++;
//             }

//             while(ttemp->next != temp){
//                 ttemp = ttemp->next;
//             }

            

//             ttemp->next = temp->next;
//             delete temp;
//         }
//     }
// };

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

#include <iostream>

using namespace std;

int main(){
    
    return 0;
}


class Node{
    public:
    int val;
    Node* next;

    Node(){
        val = 0;
        next = nullptr;
    }
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

class MyLinkedList {
    
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = nullptr;
        size = 1;  
    }
    bool lencheck(int index){
        int length = 0;

        Node* temp = head;

        while(temp != nullptr){
            temp = temp->next;
            length++;
        }

        if(index<=length-1){
            return true;
        }
        return false;
    }
    
    int get(int index) {
        if(index <= size){
            int count = 0;
            Node* temp = head;

            while(count != index){
                temp = temp->next;
                count++;
            }
            if(temp != nullptr)
            return temp->val;
            else
            return -1;
        }
        else{
            return -1;
        }
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            size++;
            return;
        }

        Node* temp = head;

        while(temp->next != nullptr){
            temp = temp->next;

        }
        temp->next = newNode;
        size++;
    }
    //can use add at index for head and tail also
    void addAtIndex(int index, int val) {
        if(index <= size){
            Node* newNode = new Node(val);

            if(index == 0 && head == nullptr){
                head = newNode;
                size++;
                return;
            }
            else if(index == 0){
                newNode->next = head;
                head = newNode;
                size++;
            }
            // if(index == size){
            //     addAtTail(val);
            //     return;
            // }
            int count = 0;
            Node* temp = head;
            Node* ttemp = head;
            while(count != index){    
                if(temp->next != nullptr)
                temp = temp->next;
                else
                temp = nullptr;

                if(count > 0){
                    ttemp = ttemp->next;
                }
                count++;
            }//can stop count != index - 1 so stop at one before index
            //ttemp start after count become 1 so stay one behind
            // if(temp != nullptr){
            //     while(ttemp->next != temp){
            //         ttemp = ttemp->next;
            //     }
            // }
            // else{
            //     while(ttemp->next != nullptr){
            //         ttemp = ttemp->next;
            //     }
            // }

            

            ttemp->next = newNode;
            newNode->next  = temp;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index <= size - 2){
            if(index ==0 && size == 2){
                head = nullptr;
                size--;
                return;
            }
            else if(index == 0){
                head = head->next;
                size--;
                return;
            }
            int count = 0;
            Node* temp = head;
            Node* ttemp = head;
            while(count != index){
                if(temp->next != nullptr)
                temp = temp->next;
                else
                temp = nullptr;

                if(count != 0){
                    ttemp = ttemp->next;
                }
                count++;
                
            }

            // while(ttemp->next != temp){
            //     ttemp = ttemp->next;
            // }

            

            ttemp->next = temp->next;
            delete temp;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */