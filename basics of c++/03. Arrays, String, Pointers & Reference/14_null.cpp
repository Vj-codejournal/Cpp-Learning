//problem with null before it see notes
#include <iostream>

using namespace std;
void fun(int x){ }
void fun(int *ptr){}
int main(){
    fun(NULL);
    //as function loading (two function same name) can go to int x and *ptr as NULL type int so to avoid use nullptr as it is a different data type
    //other than this NULL fine 
    
    return 0;
}