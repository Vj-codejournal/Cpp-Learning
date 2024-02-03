/*
a^b
b is even then a^b = a^(b/2) x a^(b/2) 
b is odd  then a^b = a x (a^(b/2) x a^(b/2) )
*/

#include <iostream>
int power(int a,int b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }

    int ans = power(a,b/2);

    // if(b%2 == 0){
    //     return power(a,b/2) * power(a,b/2);
    // }
    // else{
    //     return a * power(a,b/2) * power(a,b/2);
    // } Recursion would have been called 4 time bad approach

    if(b%2 == 0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}
using namespace std;

int main(){
    int a,b;

    cin>>a>>b;
    int ans  = power(a,b);

    cout<<ans;
    return 0;
}