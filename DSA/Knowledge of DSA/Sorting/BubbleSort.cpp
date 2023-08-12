#include <bits/stdc++.h>
#include<vector>

using namespace std;
void bubbleSort(vector<int> &arr,int n){
    for(int i = 1;i<n;i++){
        //n-1 rounds
        bool swapped = false;//part of optimisation
        for(int j = 0;j<n-i;j++){//as highest elemnt get it position in each loop so loop should reduce by 1 each time
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            } 

        }
        if(swapped == false){//already sorted that means not have to enter the other if condition so break here
            break;
        }
    }
}
int main(){
    int n,temp;
    cin>>n;
    vector<int> arr;

    for(int i = 0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    bubbleSort(arr,n);
    //vector<int> final = SelectionSort(arr,n);
    for(auto it : arr)
        cout<<it<<" ";

        
    return 0;
}