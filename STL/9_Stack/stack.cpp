#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();//pop the top element
    cout<<s.top()<<endl;
    s.push(40);
    while(s.empty() == false){
    cout<<s.top()<<endl;
    s.pop();    
    }//this will go till stack empty
    return 0;
}