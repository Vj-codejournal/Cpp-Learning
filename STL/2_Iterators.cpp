#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v =  {10,20,30,40,50};//vector can adjust its size according to elements

    vector<int> :: iterator i = v.begin();//i store the address of 1st element

    cout<<(*i)<<" ";//value at address
    i++;
    cout<<(*i)<<" ";
    i = v.end();
    i--;//to reach the last element
    cout<<(*i)<<" ";

    auto i = v.begin();
    i = next(i);//move one ahead by default
    cout<<(*i)<<" ";
    i = next(i,2);//move two ahead
    cout<<(*i)<<" ";

    i = prev(i);
    cout<<(*i)<<" ";

    advance(i,2);
    cout<<(*i)<<" ";
    return 0;
}