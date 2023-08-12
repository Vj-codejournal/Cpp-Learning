#include <iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    //output 0 1 5 6
    for(auto i : s){
        cout<<i<<endl;
    }

    // s.erase(s.begin());
    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);

    for(auto i : s){
        cout<<i<<endl;
    }

    cout<<s.count(5);//tells whether it is present or not in the set by 0 or 1

    set<int> :: iterator itr = s.find(5);//this return the iterator of the element if it is present

    //if we found address of 5 now to move forward from that
    for(auto it = itr;it != s.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}