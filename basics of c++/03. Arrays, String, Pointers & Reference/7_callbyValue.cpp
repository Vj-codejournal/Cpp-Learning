//Range based for loop problem in call by value also see lesson4
#include <iostream>

using namespace std;

int main(){
    string arr[] = {"Geeksgorgeeks","cpp course","learning"};

    for(const string &s: arr)//now reference so better perform if no & then copy each string take time
    cout<<s<<"\n";
    return 0;
}