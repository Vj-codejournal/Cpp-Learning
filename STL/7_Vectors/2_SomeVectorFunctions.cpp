#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v{10,5,20,15};
    v.pop_back();//remove last element
    for(int x:v){
        cout<<x<<" ";

    }
    cout<<v.front()<<" ";//reference to first element so if do v.front()=100 value in vector actual change//same as v[0]
    cout<<v.back()<<" ";//give reference to last elementS

    vector<int>v2{10,5,20,15};
    auto it = v2.insert(v2.begin(),100);//{100,10,5,20,15} //insert at 1st position
    //cant use v2[3] here
    //'it' iterator is assigned address of position where element inserted
    v2.insert(v2.begin() + 2,200);//it do to 3rd position ie 5 is there and insert there {100,10,200,5,20,15}
    v2.insert(v2.begin(),2,300);//insert 300 2 times at 0 1st position{300,300,100,10,200,5,20,15}

    vector<int> v3;
    v3.insert(v3.begin(),v2.begin(),v2.begin()+2);//for v2 1st to 2nd position insert in new vector and end position not included

    for(int x:v2)
        cout<<x<<" ";
    for(int x:v3)
        cout<<x<<" ";

    //Erase
    vector<int>v4{10,5,20,15};
    v4.erase(v4.begin());//erase the first element
    v4.erase(v4.begin(),v4.end()-1);//as it take start and one after the end position so here befor (5,20,15) final become (15) as end is position after 15 end -1 is 15 so remove till before that in erase function
    for(int x:v4){
        cout<<x<<" ";
    }

    v4.clear();
    cout<<v4.size()<<" ";

    if(v4.empty() == true)
        cout<<"Empty";
    else
        cout<<"Not Empty";
    
    v2.resize(3);//{300,300,100}
    v2.resize(5);//{300,300,100,0,0} given defalut value

    v.resize(8,100);//now resize instead of giving them default 0 give them 100
    //can put it in a loop v.resize(i,10)so increase one by one and put value

    
    return 0;
}