#include <iostream>

using namespace std;

int main(){
    int n,max=0;
    cin>>n;

    int arr[n];

    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    max = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
            max = arr[i];
        }
    }
    cout<<max;
    return 0;
}