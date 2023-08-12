//IO Manipulation part 1
#include <iostream>

using namespace std;

int main(){
    bool a = true;
    cout<<a<<"\n"; //1
    cout<<std::boolalpha;
    cout<<a<<"\n";//true
    cout<<std::noboolalpha;
    cout<<a;//1



    int b= 26,c=20;
    cout<<a<<" "<<b<<"\n";// 26 20
    cout<<std::hex;//now convert to hexa decimal form
    cout<<a<<" "<<b<<"\n";//1a 14
    cout<<std::oct;
    cout<<a<<" "<<b<<"\n";//32 24
    cout<<std::dec;
    cout<<a<<" "<<b<<"\n";// 26 20


    cout<<std::showbase;
    cout<<std::oct;
    cout<<b<<"\n";//032
    cout<<std::hex;
    cout<<b<<"\n";//0x1a
    cout<<std::showpos;
    cout<<a<<"\n";//+0x1a
    cout<<std::uppercase;
    cout<<a<<"\n";//+0X1A 



    return 0;
}