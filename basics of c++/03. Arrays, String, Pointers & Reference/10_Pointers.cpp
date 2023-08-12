//Pointers
#include <iostream>

using namespace std;

int main(){
    int x =10;
    int *p;
    p = &x;//address of x stored in p
    cout<<x<<"\n";
    cout<<*p<<"\n";//value at that address
    cout<<p<<"\n";//tell the address of x
    cout<<&x<<"\n";
    cout<<&p<<"\n";



    x = x +30;
    cout<<*p<<"\n";
    *p = *p + 40; //*p is the value at
    cout<<x<<"\n";


    int *p1;
    double *p2;
    string *p3;
    char *p4;

    cout<<sizeof(p1)<<"\n";//all same size as pointer only store addresses so irrespective of data type address is same type 
    cout<<sizeof(p2)<<"\n";
    cout<<sizeof(p3)<<"\n";
    cout<<sizeof(p4)<<"\n";
        

    return 0;
}

//application of pointers
//changing passed parameters in functions
//dynamic memory allocation
// DSA linked list, tree,BST use pointer cant use reference as they are constant pointer once point a variable cant change it
//to return multiple values
//use to access array elements
//if we ask address of array it will give address of 1st element so pointer is used to access other element 
//int arr[5]={1,2,3,4,5};
//cout<<&arr;