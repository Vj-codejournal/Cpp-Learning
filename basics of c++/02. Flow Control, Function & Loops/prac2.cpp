//simple calculator
#include <iostream>

using namespace std;

int main(){
    int a;
    cout<<"Which operation would you like to do?\n"
    <<"1 Addition\n2 substraction\n3 Multiplication\n";
    cin>>a;
    cout<<"Enter the two numbers:";
    int x,y;
    cin>>x>>y;
    if(a==1){
        cout<<"sum is "<<x+y;
    }
    else if(a==2){
        cout<<"substraction is "<<x-y;
    }
    else if(a==3){
        cout<<"multiplication is "<<x*y;
    }
    else{
        cout<<"invalid input";
    }
    return 0;
}