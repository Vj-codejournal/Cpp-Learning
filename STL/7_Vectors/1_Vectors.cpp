#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr1;
    int c = arr1.size();
    cout<<c;

    //vector declare,initialize,and traversal

    vector<int> v;
    v.push_back(10);
    v.push_back(5);
    v.push_back(20);
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<" ";//can be accessed like array
        //or use v.at(i) 
        //can do v[i]= 5 and it will change as return reference by it 
    }
    //different method of traversal
    vector<int> v1{10,5,20};
    for(int x : v1){ //to make changes in vector from here have to use reference int &x : v do 
        cout<<x<<" ";
    }
    int n=3,x=10;
    vector<int> v2(n,x);//n is size x is value

    for(auto it = v.begin();it!=v.end();it++)
    {//it = iterator just some variable and v.begin() give it address of start of vector
        cout<<(*it)<<" ";
    }

    //initialize vector with a array

    int arr[] = {10,5,20};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> v(arr,arr+n);//pass begin address and one after the end address to vector to make it vector
    for(auto it = v.rbegin();it!=v.rend();it++)//rbegin = reverse begin start from last element, rend point to one before start
    {
        cout<<(*it)<<" ";
    }
    return 0;
}
//cbegin ,cend,crbegin,crend also exist same as above just constant iterator cant change the element while traversal