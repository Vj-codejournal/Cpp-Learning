#include <iostream>
#include<algorithm>
using namespace std;
string decimal_to_binary(int n){
    string s ="";
    while(n>0){
        int t = n%2;
        s = s+ to_string(t);//convert int to string
        n = n/2;
    }

    reverse(s.begin(),s.end());
    return s;
    //can always use loop
}
int main(){
    int n;
    cin>>n;
    string ans = decimal_to_binary(n);
    cout<<ans;
    return 0;
}