#include <iostream>

using namespace std;
void reverse(string &s,int start,int end){
    while(start<=end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
}
int main(){
    string s;
    getline(cin,s);
    int start = 0,end ;
    int count = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i] == ' '){
            end = i-1;
            reverse(s,start,end);
            start = i+1;
        }
        if(i == s.length() - 1){
            end = i;
            reverse(s,start,end);
        }
    }

    for(int i=0;i<s.length();i++){
        cout<<s[i];
    }
    return 0;
}
    