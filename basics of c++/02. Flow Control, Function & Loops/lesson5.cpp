//function in c++ part 1

#include <iostream>

using namespace std;
void fun(){
    cout<<"fun() called\n";
}

int main(){
    cout<<"Before calling fun()\n";
    fun();
    cout<<"After calling fun()\n";
    return 0;
}