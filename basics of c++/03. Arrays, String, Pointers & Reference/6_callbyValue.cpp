//problem with call by value
#include <iostream>

using namespace std;
void fun(int x){ //just put &x here 
    x=x+5;
}
int main(){
    int x =10;//as call by value x here amd x in function fun are different saved at different address so here cout print no change 
    fun(x);
    cout<<x;//10
    return 0;
}