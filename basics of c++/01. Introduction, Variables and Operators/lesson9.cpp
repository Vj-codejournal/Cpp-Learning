//auto keywords 
/*if we write auto before a variable it will automatically
assign its  datatype. to know which data type used use typeid
and for that have to include typeinfo */
#include <typeinfo>
#include <iostream>

using namespace std;

int main(){
    auto a=10;
    auto b=15.5;
    cout<<a<<"\n"<<b;
    cout<<typeid(a).name()<<"\n"
        <<typeid(b).name();
    return 0;
}
