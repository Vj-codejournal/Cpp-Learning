//pointer vs array
#include <iostream>

using namespace std;

int main(){
    int arr[] = {10,20,30};
    int *ptr = arr;//this takes address of first element of array arr here is bydefault arr[0]
    cout<<sizeof(arr)<<"\n";// complete arr so 12 byte
    cout<<sizeof(ptr)<<"\n";//pointer so 4 byte
    cout<<*(arr+2)<<"\n";// arr is by default to 0th element so +2 now give value of 2nd element other way is arr[2]
    cout<<ptr[2];//can access using ptr with array syntex converted to *(ptr +2) use this mostly for ptr
    //can assign arr to ptr it stores one of the element but cant do opp arr = ptr is wrong
    //arr is random access means any element can be accessed by doing basic + - to do this "arr" is given the address of its first element 
    //arr[i] = *(arr +i) go to i addresses forward then access its value

    int *p1 = arr;//hold address of 1st element of arr
    int (*p2)[3]= &arr; //this is a pointer to a block of size 3 that means it now store address of complete array see notes // if we do *p2[3] this means it is a array of pointers

    cout<<*p1<<"\n";
    cout<<**p2<<"\n";//*p2 get value of arr which is still an address again * get value of 1st element
    return 0;
}