#include <iostream>
#include<utility>
using namespace std;

int main(){
    pair<int ,int>p1(10,20);//if p1; here not initialized by default 0
    //can also initalize later p1 = {10,20};
    pair<int ,string>p2(10,"GeeksForGeeks");
    cout<<p1.first<<" "<<p1.second<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;
    pair<int,int> p3 ;
    p3 = make_pair(10,20);//not used now

    //comparision operators on pairs
    cout<<(p1 == p3)<<" "//if both terms equal then only true
        <<(p1 != p3)<<" "
        <<(p1 > p3)<<" "//> < >= <= all compare the first value of both the pairs//for > < if 1st is same then compare the 2nd terms
        <<(p1 < p3)<<" ";

    return 0;
}