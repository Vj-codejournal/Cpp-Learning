//'for each' loop
//range based for loop
//Enhanced for loop
#include <iostream>
//for(variable: array/range) for each variable of that array this for loop will execute
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};

    for(int x : arr){
        cout<<x<<" ";
    }
    return 0;
}