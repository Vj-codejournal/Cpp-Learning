//https://www.codingninjas.com/studio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1

#include <iostream>
#include<vector>
using namespace std;
int findDuplicate(vector<int> &arr) 
{
    int ans = 0;
	for(int i = 0; i < arr.size(); i++)
        ans = ans^arr[i];
    for(int i = 1; i <= arr.size(); i++)
        ans = ans^i;
    return ans;
}

int main(){
    
    return 0;
}

//use map
/*
map<int,int> mp;
        
        
        for(auto it:arr)
        {
            mp[it]++;
        }
        
*/

//extra space use to store frequency

//use visited arr and recursion and where it repeat is the number 

//sort and arr[i] and arr[i+1] should not be same 


//used this one
//as 1,2,3......x.....n-1,x  , x is 2 times so xor 1 to n-1 to whole array only extra x will be left
