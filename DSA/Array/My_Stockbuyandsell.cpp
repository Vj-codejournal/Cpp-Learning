#include <iostream>
#include<vector>
using namespace std;

int findTheLowest(int *arr,int n){
    int min = arr[0];
    int k = 0;
    for(int i = 0;i<n;i++){
        if(min>arr[i]){
            min = arr[i];
            k = i;
        }


    }
    return k;

}


int main(){
    int n;
    cin>>n;
    int prices[n];

    for(int i=0;i<n;i++){
        cin>>prices[i];
    }

    int min = findTheLowest(prices,n);
    int maxprofit = 0;
    for(int i = min+1;i<n;i++){
        if(maxprofit <= prices[i]-prices[min]){
            maxprofit = prices[i]-prices[min];
        }
    }

    cout<<maxprofit;
    return 0;
}