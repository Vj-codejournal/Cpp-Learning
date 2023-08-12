#include <bits/stdc++.h>
#include<vector>
 
using namespace std;
int Partation(vector<int> &arr,int l,int h){
    int pivot = arr[l];
    int i = l;
    int j = h;

    while(i<j){
        do{
            i++;
        }while(arr[i]<= pivot);
        
        do{
            j--;
        }while(arr[j]> pivot);
        if(i<j){
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[l],arr[j]);
    return j;
}
void QuickSort(vector<int> &arr,int l,int h){
    if(l<h){//that means they are elements betwn them they are two terms

    int j = Partation(arr,l,h);
    QuickSort(arr,l,j);//as j act as infinite here
    QuickSort(arr,j+1,h);

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
    QuickSort(arr,0,n);
    //vector<int> final = SelectionSort(arr,n);
    for(auto it : arr)
        cout<<it<<" ";

        
    return 0;
}