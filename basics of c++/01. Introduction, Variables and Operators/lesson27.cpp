//assignment operator

#include <iostream>

using namespace std;

int main(){
    int x=10,y;
    y=x;
    cout<<y<<"\n";//10
    x += 10; // x = x+10
    cout<<x<<"\n";//20
    x-= 10;
    cout<<x<<"\n";//10
    x *=2;
    cout<<x<<"\n";//20
    return 0;
}