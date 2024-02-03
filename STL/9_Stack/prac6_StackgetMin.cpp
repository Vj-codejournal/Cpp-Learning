#include <iostream>
#include <stack>

using namespace std;
void mypush(stack<int> &ms,stack<int> &as,int x){
    if(ms.empty()){
        ms.push(x);
        as.push(x);
    }
    else{
        ms.push(x);
        if(as.top() >= ms.top()){
            as.push(x);
        }
    }
}
void mypop(stack<int> &ms,stack<int> &as){
    if(!ms.empty()){
        if(as.top() == ms.top()){
        as.pop();
        ms.pop();
        }
        else
        ms.pop();
    }
    
}
void getMin(stack<int> &as){
    cout<<as.top()<<endl;

}

int main(){
    //make a extrastack and push and pop only when required 
    stack<int> ms;
    stack<int> as;

    mypush(ms,as,20);
    mypush(ms,as,10);
    getMin(as);
    mypush(ms,as,5);
    getMin(as);
    mypop(ms,as);
    getMin(as);
    mypop(ms,as);
    getMin(as);



    return 0;
}