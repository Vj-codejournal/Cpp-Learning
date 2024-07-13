#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls,int dist,int cows){
    int cntCows = 1, last = stalls[0];
    for(int i = 1;i<stalls.size();i++){
        if(stalls[i] - last >= dist){
            cntCows++;
            last = stalls[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCow(vector<int> &stalls,int cows){
    sort(stalls.begin(),stalls.end());
    int low = 1, high = stalls[stalls.size()-1] - stalls[0];
    while(low <= high){
        int mid = low + (high - low)/2;
        if(canWePlace(stalls,mid,cows) == true){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return high;
}