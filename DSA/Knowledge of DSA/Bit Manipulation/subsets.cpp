#include <iostream>

using namespace std;
void subsets(int *arr,int n){
    for(int i = 0;i< (1<<n);i++){//1<<n give 2^n 
        for(int j=0;j<n;j++){// if 001 so has n digit do to each digit one by one and check if it is 1 if it is one that means that element in set
        if(i & (1<<j)){//to check for set bit at that position
        cout<<arr[j]<<" ";

        }
        

        }cout<<endl;
    }
}
int main(){
    int arr[4] = {1,2,3,4};
    subsets(arr,4);
    return 0;
}