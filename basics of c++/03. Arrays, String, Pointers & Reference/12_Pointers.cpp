#include <iostream>

using namespace std;
void fun(int arr[] , int n){//this is a pointer int *arr  to the first element so its size is 4 n = 4/4  not use sizeof here inside function pass size of arr also
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    } 
}
int main(){
    int arr[]={10,20,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    fun(arr,n);
    return 0;
}