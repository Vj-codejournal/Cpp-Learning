#include <iostream>
#include<cmath>
using namespace std;

int main(){
    string binary ;
    cout<<"Enter the binary number\n";
    cin>>binary;
    
    int n = binary.length();
    int decimal = 0;
    for(int i = n-1;i>=0;i--){
        
        decimal += ((binary[i] - '0') * pow(2,n-1- i));//as here 100 taken as character so there ascii values come when binary[i] called so convert to its integer value by removing ascii value of char '0' from it

        //or decimal += ((int)(binary[i]-'0')*base)
        //base = base*2
        
    }

    cout<<decimal;
    return 0;
}