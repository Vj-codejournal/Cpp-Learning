//find position wise closesr greater element of it
#include <iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;   
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    

    for(int i = 0;i<n;i++){
        if(i == 0){
            cout<<1<<" ";
            s.push(i);
        }
        else{
            
            if(arr[s.top()]>arr[i]){
                
                
                cout<<i - s.top()<<" ";
                s.push(i);
            }
            else{
                while(arr[s.top()]<=arr[i]){
                    
                    s.pop();
                    if(s.empty())
                    break;
                    
                }
                if(!s.empty())
                cout<<i - s.top()<<" ";
                else
                cout<<i - (-1)<<" ";

                s.push(i);
            }

        }
    }

    return 0;
} 

//worst way
//make two loops keep going back till we see bigger than the current no and count and print them

//VIDEO SOLUTION
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
    for(int i = 0;i<n;i++){
        while(s.empty() == false && arr[s.top()]<= arr[i]){
            s.pop();
        }
        int span = (s.empty())? (i+1) : (i-s.top());
        cout<<span<<" ";
        s.push(i);
    }    
    
    return 0;
}