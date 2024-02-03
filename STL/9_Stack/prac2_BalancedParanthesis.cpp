//The bracket that started latest is closed first
//jo opening bracket last aaya to jo phela closing bracket aaya hai wo uska hi hona chaiye

#include <iostream>
#include<stack>
using namespace std;
bool matching(char a,char b){
    return ((a == '(' && b == ')') ||(a == '{' && b == '}') || (a == '[' && b == ']') );
}
bool isBalanced(string str){
    stack<char> s;
    for(int i= 0;i<str.length();i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            s.push(str[i]);

        }
        else{
            if(s.empty()){
                return false;
            }
            else{
                if(matching(s.top(),str[i])){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }
    }
    if(!s.empty()){
        return false;
    }

}
int main(){
    string str = "{}([])";
    //string str = "((())";
    //string str = "{[}]";
    //string str = "{{}}}";
    if(isBalanced(str)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}