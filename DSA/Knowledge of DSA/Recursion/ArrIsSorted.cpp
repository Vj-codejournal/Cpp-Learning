#include <iostream>

using namespace std;
bool isSorted(int *arr,int size){
    if(size == 0|| size == 1){ 
        return true;
    }

    if(arr[0]>arr[1]){//as array is moved forward arr+1 so arr[0] is that address
        return false;
    }
    else{
        bool remainingPart = isSorted(arr+1,size-1);
        return remainingPart;
    }

}
int main(){
    int arr[5] = {2,4,6,8,9};
    int size = 5;

    bool ans = isSorted(arr,size);

    if(ans){
        cout<<"Array is Sorted";
    }
    return 0;
}