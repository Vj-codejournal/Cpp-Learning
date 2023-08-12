#include <iostream>

using namespace std;

int main(){
    int a =10,b=20,c=30;
    if(c>b>a)
        cout<<"y"; //> work L to R so (c>b)>a which give 1>a as c>b is true so 1 now 1>a is false so final false
    else
        cout<<"N";

    return 0;
}