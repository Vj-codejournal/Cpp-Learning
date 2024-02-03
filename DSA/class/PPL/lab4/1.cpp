#include <iostream>

using namespace std;
bool palindrome(string &s,int start,int end){
    while(start<=end){
        if(s[start] != s[end]){
            return false;
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}
int main(){
    string s;
    getline(cin,s);
    int start = 0,end ;
    int count = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i] == ' '){
            end = i-1;
            if(palindrome(s,start,end)){
                count++;
            }
            start = i+1;
        }
        if(i == s.length() - 1){
            end = i;
            if(palindrome(s,start,end)){
                count++;
            }
        }
    }

    cout<<count;
    return 0;
}
    