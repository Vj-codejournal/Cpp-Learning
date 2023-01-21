#include <iostream>
using namespace std;
int main(){
    const int x = 10;
    // x++;  can do this show error as x is now read only
    cout<<x;

    return 0;
}