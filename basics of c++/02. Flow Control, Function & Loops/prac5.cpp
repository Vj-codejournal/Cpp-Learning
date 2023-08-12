#include <iostream>

using namespace std;

int main(){
    int a;
    cin>>a;
    for(int i=1;i<20;i++){
        if(a > 10){
            a = a/10;
        }
        else{
            cout<<"The first digit is "<<a;
            break;

        }
    }

    return 0;
}