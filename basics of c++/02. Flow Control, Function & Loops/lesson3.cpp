//nested if else
//number sign and even odd program

#include <iostream>

using namespace std;

int main(){
    int x;
    cout<<"Enter a number: \n";
    cin>>x;
    if(x>0){
        cout<<"positive ";
        if(x%2==0){
            cout<<"even";
        }
        else{
            cout<<"odd";
        }
    }
    else if(x<0){
        cout<<"negative ";
        if(x%2==0){
            cout<<"even";
        }
        else{
            cout<<"odd";
        }
    }
    else{
        cout<<"zero";
    }
    return 0;
}