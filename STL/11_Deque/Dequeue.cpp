#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq = {10,20,30};
    dq.push_front(5);
    dq.push_back(50);//5 10 20 30 50
    for(auto x : dq){
        cout<<x<<" ";
    }
    cout<<dq.front()<<" "<<dq.back();// 5 50

    auto it = dq.begin();
    it++;
    dq.insert(it,20);//insert before iterator//5 20 10 20 30 50
    dq.pop_front();//20 10 20 30 50
    dq.pop_back();//20 10 20 30
    cout<<dq.size();//4
    return 0;
}