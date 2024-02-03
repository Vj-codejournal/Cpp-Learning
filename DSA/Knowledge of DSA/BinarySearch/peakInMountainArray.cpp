#include <iostream>
#include<vector>
using namespace std;
 int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() -1;
    int mid = start + (end-start)/2;

    while(start <= end){
        if(mid-1 != -1 && mid+1 != arr.size() && arr[mid] > arr[mid - 1] && arr[mid]> arr[mid+1]){
            return mid;
        }
        if(mid-1 != -1 && arr[mid] < arr[mid - 1]){
            end = mid -1;
        }
        else if(mid+1 != arr.size() && arr[mid]< arr[mid+1]){
            start = mid +1;
        }

        mid = start + (end-start)/2;
    }    
        return mid;
}
//[3,5,3,2,0] edge case
int main(){
    
    return 0;
}


int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() -1;
    int mid = start + (end-start)/2;

    while(start < end){
        if(arr[mid] < arr[mid +1]){
            start = mid +1;
        }
        else{
            end = mid; //not mid -1 as can skip peak 
        }
        mid = start + (end-start)/2;
    }    
        return mid;
}