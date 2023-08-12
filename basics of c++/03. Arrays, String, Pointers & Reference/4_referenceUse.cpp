//application of reference in c++
//mordify the passed variable
#include <iostream>

using namespace std;
void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}
int main(){
    int x =10,y=15;
    swap(x,y);
    cout<<x<<" "<<y;
    return 0;
}

//avoiding copy of large objects during function calls
#include <iostream>
#include<vector>
using namespace std;
//can put const before vector in below if we dont want to modify them
void Print(vector<int> &v){//if we didnt use & here call by value happen and copies of those 1000 elements would be made waste of memory and time
    for (int i = 0; i < 1000; i++)
    {
        for(auto x:v){
            cout<<x<<" ";
        }
    }
    
}
int main(){
    vector<int> v;
    for(int i = 0;i<1000;i++)
            v.push_back(i);//vector stores in 1000 consecutive addresses
            Print(v);

    return 0;
}

//modifications in 'for each' loop

#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vect{10,20,30,40};
    for(auto x:vect)//not mordify as x is a copy of member of vector so cant change the original vector use &x to modify
        x=x+5;
    for(auto x:vect)
        cout<<x<<" ";
    return 0;
}

//avoiding copy of larger objects in for each loop

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> vect {"geeksforgeeks practice","geeksforgeeks ids","geeksforgeeks  write"};

    for(auto x :vect){
        cout<<x<<" ";//large strings copied inefficient use reference use &x here
    }
    return 0;
}