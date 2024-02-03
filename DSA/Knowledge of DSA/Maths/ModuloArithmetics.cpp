// a % n gives remainder range from 0 to n-1 

//in Competitive Programming usually given return ans as ans moduloud 10^9 + 7 to bring a big answer in int range to avoid overflow


/*
(a mod m)+(b mod m)  mod m=a+b  mod m
(a mod m)−(b mod m)  mod m=a−b  mod m
(a mod m)⋅(b mod m)  mod m=a⋅b  mod m
*/


//Fast Exponentiation method

/*
a^b can get by for(b times) res = res * a so TC - O(N)

now

a^b = a^(b/2) * a^(b/2) if b is even 
        that gives (a^2) ^ (b/2)
a^b = a^(b/2) * a^(b/2) * a if b is odd
done with recursion ahead
TC - O(log b)

*/ 


//https://www.codingninjas.com/studio/problems/modular-exponentiation_1082146

//have to find (x^n)%m


#include <bits/stdc++.h>
using namespace std;
int modularExponentiation(int x, int n, int m) {
	int res = 1;

    while (n > 0) {
        if(n&1){//odd 
            res = (1LL *(res) * (x)%m )%m; //extra x here // typecasting to long long 
        }

        x = (1LL * (x)%m*(x)%m)%m; //extra x here
        n = n>>1; // one bit right shift give divide by 2
    }
    return res;
}

//1 is LL  type multiplied by x also make it LL 
/*
int a
int b
long long int c = a*b   a*b is int first so go  out of range before storing in c so do  a * 1LL *b so now become long long
*/