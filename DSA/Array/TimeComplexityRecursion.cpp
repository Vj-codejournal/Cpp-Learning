//factorial

/*
recurrance relation
F(n) = n * F(n-1)

base case const time let k1 and n* const time k2

T(n) = k1 + k2 + T(n-1)
T(n) = k + T(n-1)
T(n-1) = k + T(n-2)
T(n-2) = k + T(n-3)
 ....
T(1) = k + T(0)
T(0) = k1

add all
T(n) = n*k + k1

T(n) = O(n) 

or can say recursion call stack will go for n times and will take O(n) time

*/

//binary search by recursion

/*
F(n) = base case + F(n/2)
T(n) = k + T(n/2)
T(n/2) = k + T(n/4)
T(n/4) = k + T(n/8)
....
T(2) = k + T(1)
T(1) = k

add all

T(n) = a*k let it happen a times

n->n/2->n/4->....1 = n/2^a = 1 -> a = O(logn)

*/

//Merge sort

/*
        left part   right part
T(n) = k + T(n/2) + T(n/2) + k3n + k4n copy to original
                            merge all n elements

T(n) = k + 2T(n/2) +k5n   k is const ignore

T(n) = 2T(n/2) +k5n
(T(n/2) = 2T(n/4) +k5n/2 )*2 = 4T(n/4) +k5n 
(T(n/4) = 2T(n/8) +k5n/4 )*4 = 8T(n/8) +k5n

....

T(1) = k

 add

T(n) = a*nk let it happen a times

and a = logn
T(n) = O(nlogn)

*/

//fibonacci

/*
T(n) = k1 + k2 + T(n-1) + T(n-2)

T(n-1) = k + T(n-2) + T(n-3)
T(n-2) = k + T(n-3) + T(n-4)

.....

T(1) = k1
T(0) = k1

cant add

 recurssion tree see one call 2 other so on 2^n 

let each node k time -> total time  k*total node

total node = 1 + 2^1 + 2^2 + .... 2^n
                = 2^n+1 - 1

TC = k * (2^n+1 - 1)

TC = O(2^n)


*/


//SPACE Complexity

//see the size of recursion stack

/*
factorial

int a take k const space 

for fac(n) n calls in function call stack
add k n times
so SC = O(k*n)

SC = O(n)

*/

//binary search

/*
n -> n/2 -> n-4 ----> 1 so log n depth

mid take const space k

1
.
.
..
BS(n/4)
BS(n/2)
BS(n) - > k
main()
call stack

SC = k*log n
SC = O(logn)

*/

/*
Merge Sort

recursion call stack take log n space 

new array made n/4 array made then derstroyed when go back same for n/2 and n is biggest so take it

SC = log n + n
neglect log n
SC = O (n)
*/

// fibonacci make rec tree left size go to n right size go to n/2 so max depth is n of stack 
//in rec tree call go to left most part and them continue to return after that
//SC = O(n)
