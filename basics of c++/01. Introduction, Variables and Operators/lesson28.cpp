//comparision operators
#include <iostream>

using namespace std;

int main(){
    int x = 10, y= 20;
    cout<<(x<y)<<"\n" //1 as true
        <<(x>y)<<"\n" // 0
        <<(x==y)<<"\n"// they are not equal so false 0,, = is assingment it assign value == is for equality
        <<(x>=y)<<"\n"//0
        <<(x<=y)<<"\n"//1
        <<(x!=y)<<"\n";// not equal to operator so true


        // auto res = x<=>y;  added in c++20
        // if(res<0)
        //     cout<<"x is less";
        // if(res>0)
        //     cout<<"x is more";
        // else
        //     cout<<"x is same";
            

    return 0;
}