//Bit wise
//seenotes

#include <iostream>

using namespace std;

int main(){
    int x =3,y=6;
    cout<<(x&y)<<endl;
    cout<<(x|y)<<endl;
    cout<<(x^y)<<endl;
//left shift
    int a=3;
    cout<<(x<<1)<<endl;//6
    cout<<(x<<2)<<endl;//12
    int b =4;
    int c = (x<<y);//48
    cout<<c;

//right shift
    int p=3;
    cout<<(p<<1)<<endl;//16
    cout<<(p<<2)<<endl;//8
    int q =4;
    int r = (p<<q);//2
    cout<<r;

//not
    unsigned int s =1;
    cout<<(~s)<<endl;
    
    return 0;
}