//buffer 

#include <iostream>

using namespace std;

int main(){
    int x,y;
    cout<<"Enter First Integer:\n";
    cin>>x;
    cout<<"Enter second Integer:\n";
    cin>>y;
    cout<<"Multiplication is"<<(x*y);
    
    return 0;
}

/*if input 
Enter First Integer:
10 (press enter)
Enter second Integer:
20
Multiplication is 200

but if

Enter First Integer:
10 20(press enter) so now 2 values stored in buffer so when enter second integer come it will not
wait to enter a value as already has a value in buffer so use that
Enter second Integer: 
Multiplication is 200*/