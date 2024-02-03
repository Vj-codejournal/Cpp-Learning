#include <iostream>
#include <stack>

using namespace std;
void NextGreater(int *arr,int n){
    for(int i = 0;i<n;i++){

        int j;
        for(int j = i+1;j<n;j++){
            if(arr[j]>arr[i]){
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j==n){
            cout<<-1<<" ";
        }
    }
}
int main(){
    //opposite of prev greater element
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int> s;
    s.push(n-1);
    cout<<-1<<" ";
    for(int i = n-2;i>=0;i--){
        while(s.empty() == false && arr[s.top()]<= arr[i]){
            s.pop();
        }
        int biggest = (s.empty())? (-1) : (arr[s.top()]);
        cout<<biggest<<" ";
        s.push(i);
    }    
    //but output we get is in reverse order
    //to solve that store it in vaector and reverse
    return 0;
}