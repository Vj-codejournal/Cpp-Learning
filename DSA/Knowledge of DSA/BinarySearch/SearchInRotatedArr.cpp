//{7,8,1,2,3}
//key =2
//we have 2 sorted array so find pivot taki pata chale konse part mai binary search karna hai graph 1 ya 2 as we know s = 7 e = 3 and pivot  = 1 so can get the section in which BS has to be applied

#include <iostream>
#include<vector>
using namespace std;

int getPivot(vector<int>& arr,int n) {
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;

    while(start < end){
        if(arr[mid] >= arr[0]){// it is in 7 or 9 so send to right of it 
            start = mid +1;
        }
        else{//it is in 2 or 3 send to left
            end = mid; //not mid -1 as can skip  like peak
        }
        mid = start + (end-start)/2;
    }    
        return start;
}
int binarySearch(vector<int>& arr,int s,int e,int key){
    int start = s;
    int end = e;
    int mid =start + (end-start)/2;
    while(start <= end){//see the if not find till the end then to stop it
        if(arr[mid] == key){
            return mid;
        }

        //go to right part
        if(key > arr[mid]){
            start = mid +1;
        }
        else{
            end = mid -1;
        }

        mid = start + (end-start)/2;
    }
    return -1;
}
int search(vector<int>& arr, int n, int k)
{
    int pivot = getPivot(arr,n);
    int s = 0;
    int e = n-1;

    if(k>= arr[pivot] && k <= arr[n-1]){
        return binarySearch(arr,pivot,n-1,k);
    }

    else{
        return binarySearch(arr,0,pivot-1,k);
    }

}

int main(){
    
    return 0;
}