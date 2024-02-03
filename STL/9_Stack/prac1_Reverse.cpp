 #include <iostream>
 #include<stack>
 using namespace std;
 void reverse(string &str){
    stack<char> s;
    for(int i = 0;i<str.length();i++){
        s.push(str[i]);
    }
    for(int i = 0;i<str.length();i++){
        str[i] = s.top();
        s.pop();
    }
    
 }
 int main(){
    string str = "geeks";
    reverse(str);

    cout<<str;
    return 0;
 }
 //it has increased space complixity tho

 //string has inbuilt reverse function to reverse -> reverse(s.begin(),s.end());

 //stack can main use to reverse a forward list