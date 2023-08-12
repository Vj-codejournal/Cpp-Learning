// static variable in function

#include <iostream>

using namespace std;
void fun(){
    static int x =1;
    int y =1;
    x++;
    y++;
    cout<<x<<" "<<y<<endl;
}
int main(){
    fun();
    fun();
    fun();
    return 0;
}