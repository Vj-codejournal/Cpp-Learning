/*
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
*/
#include <iostream>

using namespace std;
int fib(int n) {
        if(n==0)return 0;
        if(n == 1)return 1;

        return fib(n-1)+fib(n-2) ;
        //in this function call stack left part of recursion called first then left part after left come back finished 
    }
int main(){
    
    return 0;
}