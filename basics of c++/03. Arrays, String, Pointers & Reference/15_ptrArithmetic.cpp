#include <iostream>

using namespace std;

int main(){
    int arr[]={10,20,30,40};
    int *ptr = arr;
    cout<< *ptr <<" "<<ptr<<"\n";
    ptr++;//as a int ptr move 4 byte if a double ptr then move 8 byte and 1 byte for char
    cout<< *ptr << " "<< ptr<<"\n";
    ptr--;
    cout<< *ptr << " "<< ptr<<"\n";
    ptr = ptr + 3;//move 12 bytes ahead 4x3
    cout<< *ptr << " "<< ptr<<"\n";


    int *ptr1 = arr;
    cout<< *ptr1 << " "<< ptr1<<"\n";
    int *ptr2 = ptr1 +3;
    cout<< *ptr2 << " "<< ptr2<<"\n";
    cout<<(ptr2-ptr1);//give no of objects between them so here 3 terms of array come in between
    //can substract similar type of pointer only

    return 0;
}