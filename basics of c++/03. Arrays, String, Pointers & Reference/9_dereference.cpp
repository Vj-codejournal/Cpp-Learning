//Address and dereference
//& tells address of a variable
//* give value at that address if put it  before &

#include <iostream>

using namespace std;

int main(){
    int x =10;
    cout<<&x<<"\n";
    cout<<*(&x);
    return 0;
}