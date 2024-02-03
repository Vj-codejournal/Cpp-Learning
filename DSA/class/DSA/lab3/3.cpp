#include <iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t-- > 0){
    int l,r;
    cin>>l>>r;
    int temp = l;
    int stopper =0;
    while (temp <= r){
        if(temp == 1){
            temp++;
        }
        int a,b;
        if(temp%2 == 0)
        a = temp/2,b=temp/2;
        else
        a = (temp-1)/2,b = (temp+1)/2;

        while(a+b <= r){
            if(__gcd(a,b) != 1){
                stopper =1;
                break;
            }
            a+=2;
            b+=2;
        }
        
        if(stopper){
            cout<<a<<" "<<b<<endl;
            break;
        }
        temp++;
    }
    if(stopper == 0 ){
        cout<<"-1"<<endl;
    }
    }
    return 0;
}