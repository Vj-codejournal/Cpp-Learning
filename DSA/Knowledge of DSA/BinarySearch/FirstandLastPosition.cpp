//First and Last Position of an Element In Sorted Array

#include <iostream>
#include<vector>
using namespace std;
//linear search

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> ans(-1,-1);
    for(int i=0;i<n;i++){
        if(arr[i] == k && (arr[i-1] != k || i-1 == -1)){
            ans.first = i;
        }
        
        if(arr[i] == k && (arr[i+1] != k || i+1 ==n)){
            ans.second = i;
        }
        

    }
    return ans;
}

//binary search
int firstOcc(vector<int>& arr,int n,int k){
    int start = 0;
    int end = n-1;
    int mid =start + (end-start)/2;
    int ans = -1;
     while(start <= end){
        if(arr[mid] == k){
            ans = mid;
            end = mid -1;//send it to left of it to find any more key occurence are there and if not loop will complete and ans will be returned 
        }

        //go to right part
        else if(k > arr[mid]){
            start = mid +1;
        }
        else{
            end = mid -1;
        }

        mid = start + (end-start)/2;
    }
    return ans;
}
int lastOcc(vector<int>& arr,int n,int k){
    int start = 0;
    int end = n-1;
    int mid =start + (end-start)/2;
    int ans = -1;
     while(start <= end){
        if(arr[mid] == k){
            ans = mid;
            start = mid +1; 
        }

        //go to right part
        else if(k > arr[mid]){
            start = mid +1;
        }
        else{
            end = mid -1;
        }

        mid = start + (end-start)/2;
    }
    return ans;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> ans;
    ans.first = firstOcc(arr,n,k);
    ans.second = lastOcc(arr,n,k);

    return ans;
}
int main(){
    
    return 0;
}

//Q total no of occurance 
//can get firstocc and last Occ so (last index - first index)+1