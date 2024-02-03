#include <bits/stdc++.h> 
using namespace std;
void inserter(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();
    inserter(myStack,x);
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    inserter(myStack,x);
    return myStack;
}

int main(){
    stack<int> inputStack;
    int n;
    int x;
    int t;
    cin>>t;

    while(t-->0){
        cin>>n>>x;
        int a;
        for(int i = 0;i<n;i++){
            cin>>a;
            inputStack.push(a);

        }

        pushAtBottom(inputStack,x);

    }
}