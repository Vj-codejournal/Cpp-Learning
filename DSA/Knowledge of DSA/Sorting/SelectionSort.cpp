#include <bits/stdc++.h>
#include<vector>

using namespace std;
void SelectionSort(vector<int> &arr,int n){
    for(int i = 0;i<n-1;i++){
        int minIndex =i;//move the index 

        for(int j = i+1;j<n;j++){//to find the minimum in each loop for placing on the i th index
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }

        }
        swap(arr[minIndex],arr[i]);//min index is j now so i and j swapped min number take the first position
    }
    //return arr;
}
int main(){
    int n,temp;
    cin>>n;
    vector<int> arr;

    for(int i = 0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    SelectionSort(arr,n);
    //vector<int> final = SelectionSort(arr,n);
    for(auto it : arr)
        cout<<it<<" ";

        
    return 0;
}