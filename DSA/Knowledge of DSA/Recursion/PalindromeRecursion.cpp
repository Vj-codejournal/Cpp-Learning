
#include <iostream>

using namespace std;
bool Palindrome(string &s,int i,int j){
    if(i>j){
        return true;
    }

    if(s[i]!= s[j])return false;

    else return Palindrome(s,i+1,j-1);
}
int main(){
    string name = "varra";

    cout<<Palindrome(name,0,name.length()-1);
   
    return 0;
} 