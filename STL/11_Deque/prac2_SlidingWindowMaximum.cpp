
//BRUTE
#include <iostream>

using namespace std;

void maxSub(int *arr,int n,int k){
    for(int i =0;i<n-k+1;i++){
        int max =0 ;
        for(int j = i;j<i+k;j++){
            if(arr[j]>arr[max]){
                max = j;
            }
        }
        cout<<arr[max]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int k;
    cin>>k;

    maxSub(arr,n,k);
    return 0;
}

//EFFICIENT
//deque
//take size size of deque as k and front store max value of it
#include <iostream>

using namespace std;

int main(){
    
    return 0;
}