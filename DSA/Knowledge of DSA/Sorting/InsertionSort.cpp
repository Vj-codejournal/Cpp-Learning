#include <bits/stdc++.h>
#include<vector>
 
using namespace std;
void InsertionSort(vector<int> &arr,int n){
    for(int i = 1;i<n;i++){
        int temp = arr[i];
        //inner loop compare i th to i-1 se 0 index for > < 
        int j=i-1;
        for(;j>=0;j--){
            if(arr[j] > temp){//when left case have to shift so make prev term shift 1 position
            arr[j+1] = arr[j];

            }
            else{//right position case that means the one we were checking is greater so no shift now it should come there only
            break;
                
            }
        }
        arr[j+1] = temp;//assigned it position as other all which are greater than it shift forward
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
    InsertionSort(arr,n);
    //vector<int> final = SelectionSort(arr,n);
    for(auto it : arr)
        cout<<it<<" ";

        
    return 0;
}