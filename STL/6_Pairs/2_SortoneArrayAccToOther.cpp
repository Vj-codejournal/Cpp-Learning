#include <iostream>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr1[n];
    char arr2[n];
    for(int i =0 ;i<n;i++){
        cin>>arr1[i];
    }
    for(int i =0 ;i<n;i++){
        cin>>arr2[i];
    }
    pair<int,char> p[n];

    for(int i =0 ;i<n;i++){
        p[i] = {arr1[i],arr2[i]};
    }
    sort(p,p +n);//it will sort pairs 1st elements that are numbers what we want
    for (int i = 0; i < n; i++)
    {
        cout<<p[i].second<<endl;
    }
    
    return 0;
}