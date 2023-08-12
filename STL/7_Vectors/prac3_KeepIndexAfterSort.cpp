#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

void printSortedByMarks(vector<pair<int,int>> v,int n){
    
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second;
        cout<<endl; 
    }

}
int main(){
    int arr[] = {20,40,30,10};
    int n =4;
    vector<pair<int,int>> p1;
    for(int i=0;i<n;i++){
        p1.push_back({arr[i],i});
    }
    printSortedByMarks(p1,n);
    return 0;
}