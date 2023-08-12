#include <iostream>
#include<map>
using namespace std;

int main(){
    map<int,string> m;
    m[1] = "babber";
    m[2] = "love";
    m[13] = "kudos";
    m.insert({5,"Bheem"});

    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<m.count(13)<<endl;

    //m.erase(13);//just give key to erase

    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it = m.find(5);
    for(auto i = it;i != m.end();i++){
        cout<<(*i).first<<endl;
    }
    return 0;
}