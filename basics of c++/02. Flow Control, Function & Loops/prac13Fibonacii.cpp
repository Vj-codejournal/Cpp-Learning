//Fibonacii numbers
//1 1 2 3 5 8 if fibonacii start at 0 them n==0 make else if a += 0
#include <iostream>

using namespace std;
int fibonacci(int n){
    int ans =0;
    if (n ==0 or n == 1){
        ans +=1;
    }
    else{
        ans = fibonacci(n-1) + fibonacci(n-2);
    }//can use array the same
    return ans;
}
int main(){
    int a;
    cin>>a;
    cout<<fibonacci(a);
    return 0;
}

//fibonacii by for loop
//0 1 1 2 3 5 8
// #include <iostream>

// using namespace std;

// int main(){
//     int n,ans =0;
//     cin>>n;
//     int a=0,b=1,c;
//     cout<<"0 1 ";
//     for(int i=1;i<=n-1;i++){//n-1 as 0th and 1st term already mentioned so c start 2nd term;
//         c= a+b;
//         cout<<c<<" ";
//         a=b;
//         b=c;
    
//     }
//     return 0;
// }