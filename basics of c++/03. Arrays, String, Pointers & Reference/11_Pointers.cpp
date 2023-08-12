#include <iostream>

using namespace std;
void fun(int *a){
    *a = *a+5; //pointer store address so use * to get value at that address
}
int main(){
    //if dont use pointer in function takes a copy and cant make actual change in variable
    //same for strings as reference too long copies made
    int x = 10;
    fun(&x);
    cout<<x;
    return 0;
}


