//else if function
//positive negitive zero program

#include <iostream>

using namespace std;

int main(){
    int x;
    cout<<"Enter a number: \n";
    cin>>x;
    if(x<0){
        cout<<"negative";
    }
    else if(x>0){
        cout<<"positive";
    }
    else{
        cout<<"zero";
    }
    return 0;
}