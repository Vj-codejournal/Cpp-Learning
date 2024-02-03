/*
Big O notation - Upper Bound - worst case

theta - avg case complixity

omega - Lower bound - best case complixity


O(N!)    ^
O(2^n)   |
O(N^3)   |
O(N^2)   |
O(NlogN) |
O(N)     |
O(Log N) |complixity
O(1)     |


f(n) = 2n^2 + 3n + 1 take biggest only
so O(N^2)


constraints 1<n<10^6 or 1<n<1000 given in question

n               time complexity
<[10..11]       O(N!),O(n^a)
<[15...18]      O(2^N * N^2)
<100            O(N^4)
<400            O(N^3)
<2000           O(N^2*log N)
<10^4           O(N^2)
<10^6           O(N*log N)
<10^8           O(N),O(log N) for 10^8 can use anything above of this get TLE



Space complexity 
for int a or int b const space O(1)
for arr[5] also const so O(1)
vector<int> V(n); here n is vary so O(n)


*/

