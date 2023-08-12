////give the elements of array smaller than the given number
#include <iostream>
#include<vector>
using namespace std;
vector<int> getSmaller(int *arr,int n,int k){
    vector<int>res;
    for(int i =0 ;i<n;i++){
        if(arr[i]<k)
            res.push_back(arr[i]);
    }
    return res;
} //use vector as we dont know the size of the final array
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<int> res = getSmaller(arr,n,k);//copy complete returned vector
    for(const int &x:res){
        cout<<x<<" ";
    }
    return 0;
}