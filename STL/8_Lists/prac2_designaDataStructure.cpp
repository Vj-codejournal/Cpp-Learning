//create a data structure 
//insert(x) insert at end
//replace(x,seq) replace at first occurance 
//print

//if use array vector insert at O(1) but replace first delete shift everything back by 1 then move all elements forward too costly

#include <iostream>
#include <list>
#include <algorithm>
#include<vector>

using namespace std;
list<int> l;
void insert(int x){l.push_back(x);}//had to use list as forward list dont have push_back
void print(){
    for(int x:l){
        cout<<x<<" ";
    }
    cout<<endl;
}
void replace(int x, vector<int> &seq){//can pass it as a sequence  list also instead of vector
auto it =find(l.begin(),l.end(),x);
if(it == l.end())//one after the end of list
return;

it  = l.erase(it);//iterator shift to next to it
l.insert(it,seq.begin(),seq.end());//insert before the iterator

}
int main(){
    insert(3);
    insert(10);
    insert(2);
    insert(10);
    print();
    vector<int> seq = {20,30,40};
    replace(10,seq);
    print();

    return 0;
}