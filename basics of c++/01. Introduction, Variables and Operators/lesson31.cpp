#include <iostream>

using namespace std;

int main(){
    int x=1,y=2,z=3,a;
    a=(x,y,z); //, first evaluate the first value then the second and result is second and it go L to R. so x,y exicute give y then y,z give z so a = z 
    cout<<a;
    int b =x,y,z;//, priority less than = so b = x first assign no need to go further
    cout<<b;

    return 0;
}