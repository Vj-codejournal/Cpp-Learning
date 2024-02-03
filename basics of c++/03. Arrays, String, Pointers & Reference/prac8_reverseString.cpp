#include <iostream>

using namespace std;

int main(){
    string str ;
    getline(cin,str);
    int n = str.length();
    for(int i=n-1;i>=0;i--){
        cout<<str[i];
    }
    return 0;
}

//or

#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    string newstring = "";//empty

    int l = s.length();
    while(l >= 0){
        newstring = newstring + s[l];//newstring empty so s[l] add new alphabet one by one
        l--;
    }
    cout<<newstring; 
    return 0;
}


//efficient 

#include <iostream>

using namespace std;

int main(){
    string s = "varun";
    int i = 0;
    int j = s.length () -1;
    while(i<=j){
        swap(s[i],s[j]);

        i++;
        j--;
    }
    return 0;
}


//stack method

#include <iostream>
#include<stack>
using namespace std;

int main(){
    string str = "varun";
    stack<char> s;
    for(int i = 0;i<str.length();i++){
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while(!s.empty()){
        char  ch = s.top();
        ans.push_back(ch);
        s.pop();

    }
    cout<<ans<<endl;
    return 0;
}