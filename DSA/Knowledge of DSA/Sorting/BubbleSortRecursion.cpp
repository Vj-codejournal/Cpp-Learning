#include <iostream>

using namespace std;
void BubSort(int *arr,int n){
    if(n == 0 || n == 1){
        return;
    }

    for(int i = 0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    BubSort(arr,n-1);
}
int main(){
    int arr[5] = {2,5,1,6,9};

    BubSort(arr,5);
    return 0;
}