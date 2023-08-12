#include <iostream>
#include<vector>
using namespace std;

int main(){
    int m;
    cout<<"Enter the number of rows:";
    cin>>m;
    int n =0;
    vector<vector<int>> arr;

    for(int i=0;i<m;i++){
        vector<int> v;

        for(int j =0 ;j<=n;j++){
            if(j==0 || j==n){
                v.push_back(1);
            }
            else{
                v.push_back(arr[i-1][j-1]+arr[i-1][j]);
            }
        }
        arr.push_back(v);
        n++;
    }
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<=k;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        k++;
    }
    return 0;
}