#include <iostream>
using namespace std;
int x =20;
int main(){
    int x = 10;
    {
        int x =30 ;
        cout<<x;  //so 30 considered as inner most each {} bring a scope here 2 local and 1 global scope
    }
    return 0;
}