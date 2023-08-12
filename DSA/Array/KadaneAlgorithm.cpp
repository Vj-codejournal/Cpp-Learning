#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n,max=0;
    cin>>n;
    int temp =n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int k = 0;
    vector<int> sub;
    
    while(temp>0){
    for(int i =0;i<temp;i++){
        int sum =0;
        for(int m=i;m<=i+k;m++){
            sum += arr[m]; 
        }
        
        if(sum >= max){
            max = sum;
            //vector<int> sub(arr[i],arr[i+k+1]);
            sub.clear();
            for(int j = i;j<= i+k;j++){
                sub.push_back(arr[j]);
            }


        }
    }
    k++;
    temp--;
    }
    
    cout<<max<<"\n";
    for(int i =0;i<sub.size();i++){
        cout<<sub[i]<<" ";
        
    }
    
    return 0;
}