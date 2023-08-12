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