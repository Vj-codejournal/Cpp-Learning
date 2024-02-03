#include <iostream>
#include<stack>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int> s;
    s.push(0);
    for(int i = 0;i<n;i++){
        while(s.empty() == false && arr[s.top()]<= arr[i]){
            s.pop();
        }
        int biggest = (s.empty())? (-1) : (arr[s.top()]);
        cout<<biggest<<" ";
        s.push(i);
    }    
    
    return 0;
}