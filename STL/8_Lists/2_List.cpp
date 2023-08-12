#include <iostream>
#include <list>

using namespace std;

int main(){
    list <int> l;
    l.push_back(10); // 10
    l.push_back(20);// 10,20
    l.push_front(5);//5,10,20 

    l.pop_front();//10,20
    l.pop_back();//10

    for(auto it = l.begin();it != l.end();it++){
        cout<<*it<<" ";

    }//auto is in place of list<int> :: iterator
    list<int> l1 = {10,2,5,20};
    l1.pop_front();//10 removed
    l1.pop_back();//20 removed 
    l1.push_front(20);//20,2,5

    auto it = l1.begin();
    it++;//go to next element
    it = l1.insert(it,15);//as it is equaled to iterator it get the address of inserted element that is 15//insert before the iterator, iterator at 2 so 20,15,2,5
    l1.insert(it,2,7);//add7 two times 20,7,7,15,2,5 
      //its iterator points to this 7 now ^
      cout<<l1.front()<<" "<<l1.back();//front give reference of the front element
      cout<<" "<<l1.size();


    auto it2 = l1.begin();

    it2= l1.erase(it2);//erase 20 and iterator at 7
    l1.remove(2); // remove all occurance of 2 in the list
    //7,7,15,5
    l1.merge(l); //merge l into l1 and make l empty
    //7,7,15,5,10
    //there are sort reverse and unique function too
    return 0;
}