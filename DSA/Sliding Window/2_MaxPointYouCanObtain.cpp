#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i = 0;i<k;i++){
            sum += cardPoints[i];
        }
        maxSum = max(maxSum,sum);

        int i = k-1,j = cardPoints.size()-1;

        for(int x = i;x>=0;x--){
            sum -= cardPoints[x];
            sum += cardPoints[j];

            maxSum = max(sum,maxSum);
            j--;
        }

        return maxSum;
    }
};

