//dont have circular linked list in stl so use normal list to make it behave like a circular linked list

//n person in every iteration have to kill kth person till only one left
#include <iostream>
#include<list>
using namespace std;
int getSurv(int n,int k){
    list<int> l;
    for(int i = 0;i<n;i++){
        l.push_back(i);

    }
    auto it = l.begin();

    while(l.size()>1){
        for(int count =1;count<k;count++){
            it++;
            if(it == l.end()) // made it circular
            it = l.begin();
        }
        it=l.erase(it);//return next of erased item
        if(it == l.end()){
            it = l.begin();
        }
    }
    return *(l.begin());
}

int main(){
    int n,k;
    cin>>n>>k;

    cout<<getSurv(n,k);    
    return 0;
}