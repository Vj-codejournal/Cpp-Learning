#include <iostream>
#include<stack>
using namespace std;
void sortStack(stack<int> &inputStack)
{
	if(inputStack.empty()||inputStack.size() == 1){
        return;
    }

    int num = inputStack.top();
    inputStack.pop();
    stack<int> s1, s2;

    while(!inputStack.empty()){
        if(inputStack.top()<num){
            s1.push(inputStack.top());
            inputStack.pop();
        }
        else{
            s2.push(inputStack.top());
            inputStack.pop();
        }
    }
    sortStack(s1);
    sortStack(s2);
    s2.push(num);

    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }

    // while(!s2.empty()){
    //     cout<<s2.top()<<" ";
    //     inputStack.push(s2.top());
    //     s2.pop();
    // }

}

// void mediator(stack<int> &inputStack){
//     sortStack(inputStack);
//      while(!s2.empty()){
//         cout<<s2.top()<<" ";
//         //inputStack.push(s2.top());
//         s2.pop();
//     }
// }
int main(){
    stack<int> inputStack;
    int n;
    
    int t;
    cin>>t;

    while(t-->0){
        cin>>n;
        int a;
        for(int i = 0;i<n;i++){
            cin>>a;
            inputStack.push(a);

        }

        //mediator(inputStack);

    }
    return 0;
}