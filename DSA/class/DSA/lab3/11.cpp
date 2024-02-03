#include <iostream>
#include<utility>

using namespace std;

int main(){
    int t;
    cin>>t;
    
    while (t-- > 0){
        int n;
        cin>>n;
        pair<int,int>p[n];
        for(int i = 0;i<n;i++){
            cin>>p[i].first>>p[i].second;
        }
         
        int minRoom = 0;
        int current = minRoom;
        int i=1;
        while(true){
            current++;
            int temp;
            if(current == p[i].first){
                if(p[i].second%2 == 0){
                    minRoom = current;
                    temp = p[i].second/2;

                }
                else{
                    temp = p[i].second/2;
                }
            }
        }

        
        
    }
    return 0;
}