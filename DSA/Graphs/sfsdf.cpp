#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t-->0){
        int n,k;
     
        cin>>n>>k;
        set<int> initial;
        for(int i = 1;i<=n;i++){
            initial.insert(i);
        }
        set<int> s;
        int count = 0;
        for(int i = 1;i<=n;i++){
            if(i%2 != 0){
                s.insert(i);
                initial.erase(i);
                count++;
            }
            if(count == k){
                cout<<i<<endl;
                break;
            }
        }
        int mul = 2;

        while(!initial.empty()){
            for(auto it: s){
                initial.find(mul*it);
            }
        }


    }
    return 0;
}