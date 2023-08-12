#include <iostream>
#include<vector>
using namespace std;
void fun(vector<int> &v){//if no & will send a copy so will not be able to make changes in vector from function//if not want to modify use const before vector
    v.push_back(10);
    v.push_back(20);
}
int main(){
    vector<int>v{5,7,8};
    fun(v);
    for(int x:v)
        cout<<x<<" ";
    return 0;
}