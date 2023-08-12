#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(30);
    v.push_back(30);
    v.push_back(30);
    cout<<v.size()<<" "<<v.capacity();
    return 0; 
}