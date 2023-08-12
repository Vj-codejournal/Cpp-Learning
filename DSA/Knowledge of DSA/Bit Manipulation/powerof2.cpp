#include <iostream>

using namespace std;
bool ispowerof2(int n){
    return (n && !(n & n-1));//n && is used for a base case when n = 0  n-1 not possible so ny n && it will return 0 at that only
}
int main(){
    int n;
    cin>>n;

    if(ispowerof2(n)){
        cout<<"Entered no is power of 2";
    }
    return 0;
}