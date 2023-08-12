#include <iostream>

using namespace std;

int main(){
    int n = 4;

    for(int i=0;i<n;i++){
        for(int j = 1;j<=10;j++){
            cout<<j*(i+1)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}