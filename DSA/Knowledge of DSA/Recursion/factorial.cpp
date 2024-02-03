/*
Recurssion
When a function call itself and a base case to stop recursion 
when a big problem can be solved using a smaller problem
ek case/step solve karna hai baki sab hote jayange and sab steps similar kam kar rahe hai
Factorial 
5! = 5x4x3x2x1
5! = 5x4!
n! = n x n-1!
f(n) = n x f(n-1);

if a function has 2 recursive calls in  it do the first one till the end then go to the second function from the last  like in trees
*/

#include <iostream>

using namespace std;
int factorial(int n){
    if(n == 0) return 1;

    int smallerProblem = factorial(n-1);
    int biggerProblem = n*smallerProblem;

    return biggerProblem;
}
int main(){
    int m;
     
    cin>>m;

    cout<<factorial(m);
    return 0;
}

/*  tail recursion          head recursion
    fun(){                  fun(){
        base case               base case    

        processing              recursive call

        recursive call          processing
    }                       }

    procesing can have increment ,count, print etc.
*/