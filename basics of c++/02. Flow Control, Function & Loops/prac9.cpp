#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int c=1;
    for(int i=1;i<=n;i++){
        c *= i;
    }
    cout<<c;
    return 0;
}

//or use recurssion

/*

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int ans =1;
    while(n>0){
        ans = ans*n;
        n--;
    }
    cout<<ans;
    return 0;
}
*/