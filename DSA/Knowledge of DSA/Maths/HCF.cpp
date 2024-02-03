//greatest number that divides two numbers perfectly

//24 = 2x2x2x3
//72 = 2x2x2x3x3
//so hcf = 2x2x2x3

//using Euclid Algo
//gcd(a,b) = gcd(a-b,b) or gcd(a%b,b)
//till a%b becomes 0 than b is the answer

#include <iostream>
int gcd(int a,int b){
    if(a==0)
    return b;
    if(b==0)
    return a;

    while(a!=b){
        if(a>b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

int gcd2(int a,int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }

    int ans;
    if(a>b)
    ans = gcd2(a%b,b);
    else
    ans = gcd2(a,b%a);
    return ans;
}
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;

    int ans = gcd2(a,b);
    cout<<ans;
    return 0;
}
//Time Complexity: O(log min(a, b))

//relation between lcm and gcd
//lcm(a,b) * gcd(a,b) = a*b

//write a s