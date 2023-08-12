#include <iostream>
#include <forward_list>

using namespace std;

int main(){
    forward_list<int> l = {10,15,20};//if no number create empty list
    l.push_front(5);//5 added to front of linked list 
    l.push_front(3); // 3 -> 5 -> 10 -> 15 -> 20
    l.pop_front();//remmove 3 that is at front of linked list
    for(int x:l){//same as vector
        cout<<x<<" ";
    }
    cout<<endl;
    forward_list<int> l2;
    //for(int i = 0 ;i<5;i++) if do this not make a list one by one it just keeps reassigning a singke value to list
    l2.assign({10,20,30,10}); //assign values to the list 10 -> 20 -> 30 -> 10
    l2.remove(10);//remove all 10 from list
    
    for(auto it = l2.begin();it != l2.end();it++)//auto used in place of forward_list<int> :: iterator stores address
        cout<<(*it)<<" ";
    //other ways to assign
   // l2.assign(l.begin(),l.end());//remove all the old emements of l2 reassign with elements of l
    //can't do l.begin() + 2 to start from 3rd element

    //l2.assign(5,10);//10,10,10,10,10 in linked list

    //to access a element of list
    auto it2 = l2.begin();
    it2++;
    cout<< *it2;

    //more functions

    forward_list<int> list = {15,20,30};
    auto it = list.insert_after(list.begin(),10); // 15,10,20,30
    it = list.insert_after(it,{2,3,5});//after above function it point at 10 so insert after that
    //15,10,2,3,5,20,30
    it = list.emplace_after(it,40);//exact same as insert after just more optimised for user defined data types
    it = list.erase_after(it);// 20 is after 40 it is removed //and it point to 30 now
    //erase_after(it,list.end())//erase till end and point to a blank space after 40 where end() usually is
    for(int x:list){ 
        cout<<x<<" ";
    }

    //clear() - clears the list
    //empty() - checks if list is empty
    //reverse() - reverse the list 
        //forward_list<int> l = {10,20,30};
        //l.reverse()

    //merge() - merge 2nd list into 1st so 2nd become empty it should be 2 sorted list
    //so arrange combined in a sorted way also
        
        //forward_list<int> l1 = {10,20,30};
        //forward_list<int> l2 = {5,15};
        //l1.merge(l2); 5,10,15,20,30

    //sort()- sort the list 
        //forward_list<int> l1 = {5,15,10};
        //l1.sort();//can pass greater function to sort in decreasing order
        //pass costimised funciton to sort in particular order

        
    return 0;
}