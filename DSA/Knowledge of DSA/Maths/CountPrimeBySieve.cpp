//https://leetcode.com/problems/count-primes/
//have to do it in better time complixity than O(N)
//count prime
//Sieve of Eratosthenes
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool>  prime(n+1,true);
        prime[0] = prime[1] = false;

        for(int i = 2;i<n;i++){
            if(prime[i]){
                cnt++;

                for(int j = 2*i;j<n;j = j+i){//can start from i*i here as before it are all dealt with
                    prime[j] = false;
                }
            }
        }
        return cnt;
    }
};
int main(){
    
    return 0;
}

/*
n = 40 

so 1 to 40
have to check only 2 to 39 
-- mark every number as prime number
-- 2 is considered prime so cancel all its multiples till 40 so 4 6 8 10 12 14 16 18 20 .... cancelled as not prime
--3 not cutted so prime now make all its multiples non prime 6 9 12 15....
-- 4 is cutted skip
--5 is not cutted so prime cut all its multiples 10 15... 
--do so on for all left


//complixity
TC 

n total
2 pe gaye 2 ke sare multiples ko kaat diya to uthni bar chala loop and total 2 se divisible hote hai 
GIF[n/2] same for 3 -> n/3

n/2 + n/3 + n/5 + n/7 + n/11 ... ye total number of iterations hai itni bar loop chaelga 
n(1/2+1/3+1/5+1/7...) it is a HP gives log(log n)//taylor series

so TC - n * log(log n)
*/

//SC - O(N) can be too large when n is large so use Segmented Sieve

//SEGMENTED SIEVE

#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        if (n < 2) {
            return cnt;
        }
        
        int limit = sqrt(n) + 1;
        std::vector<bool> prime(limit, true);
        std::vector<int> primes;
        
        for (int i = 2; i < limit; i++) {
            if (prime[i]) {
                primes.push_back(i);
                for (int j = i * i; j < limit; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        int low = limit;
        int high = 2 * limit;
        
        while (low < n) {
            if (high > n) {
                high = n;
            }
            
            std::vector<bool> segment(high - low, true);
            
            for (int p : primes) {
                int start = std::max(p * p, (low / p) * p);
                for (int j = start; j < high; j += p) {
                    segment[j - low] = false;
                }
            }
            
            for (int i = 0; i < high - low; i++) {
                if (segment[i]) {
                    cnt++;
                }
            }
            
            low += limit;
            high += limit;
        }
        
        return cnt;
    }
};