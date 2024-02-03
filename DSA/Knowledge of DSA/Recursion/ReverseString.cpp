//just like loop method swap first and last

#include <iostream>

using namespace std;
void Reverse(string &s,int i,int j){
    if(i>j){
        return;
    }

    swap(s[i],s[j]);

    Reverse(s,i+1,j-1);
}
int main(){
    string name = "varun";

    Reverse(name,0,name.length()-1);
    cout<<name;
    return 0;
}

//j can be replaced by n-i-1