// if and else
//odd even identifier

#include <iostream>

using namespace std;

int main(){
    int x;
    cout<<"Enter a number: \n";
    cin>>x;
    if(x % 2 ==0){
        cout<<"The entered number is even";
    }
    else{
        cout<<"The entered number is odd";
    }
    return 0;
}