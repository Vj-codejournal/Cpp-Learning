#include <iostream>
#include<vector>

using namespace std;

vector<int> sorter(vector<int> &arr){
    while(true){
        int count =0;

        for(int i = 0 ;i<(arr.size()-1);i++){
            if(arr[i]>arr[i+1]){ //use < sign for decending order
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                count++;
            }
        }
        if(count<1){//this checks for sorted if no change is made break the infinite loop
            break;
        }
    }

    return arr;
}

int main(){
    int n,a;
    cin>>n;
    vector<int> arr;

    for(int i = 0;i<n;i++){
       
        cin>>a;
        arr.push_back(a);
    }    

    vector<int> final = sorter(arr);

    for(auto it : final){
        cout<<(it)<<" ";
    }
    return 0;
}