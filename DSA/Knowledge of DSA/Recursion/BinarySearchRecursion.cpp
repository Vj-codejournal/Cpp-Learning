//array must be sorted
#include <iostream>

using namespace std;
bool BinarySearch(int *arr,int s,int e,int key){

    if(s>e){
        return false;
    }
    int mid = s + (e-s)/2;

    if(arr[mid] == key){
        return true;
    }
    else if(arr[mid]< key){
        BinarySearch(arr,mid+1,e,key);
    }
    else{
        BinarySearch(arr,s,mid-1,key);
    }



}
int main(){
    int arr[6]={2,4,6,10,14,16};
    int key = 16;

    cout<<BinarySearch(arr,0,5,key);
    return 0;
}