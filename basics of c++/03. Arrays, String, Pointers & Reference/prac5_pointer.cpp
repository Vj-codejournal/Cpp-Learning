
#include <iostream>

using namespace std;

int main(){
    int arr[]={10,20};
    int *ptr = arr;
    ++*ptr;
    cout<<arr[0]<<" ";
    cout<<arr[1]<<" ";
    cout<<*ptr<<" ";
    //++ and * have same precedence and both right associative
    // so it become ++(*ptr) firrst get value at address then increment and increment in ptr so also change in array

    *ptr++;
    cout<<arr[0]<<" ";
    cout<<arr[1]<<" ";
    cout<<*ptr<<" ";
    //postfix++ has higher precedence than * so ++ happen first go to next position and get value *(ptr++)

    ++*ptr++;
    cout<<arr[0]<<" ";
    cout<<arr[1]<<" ";
    cout<<*ptr<<" ";
    //postfix first go to 20 then prefix and * go from right so star get value and ++ increase it
    return 0;
}
