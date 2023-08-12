//floating point (manipulating default format)

#include <iostream>
#include<iomanip>

using namespace std;

int main(){
    //setprecision(n) -change the default precision
    cout<<std::setprecision(4);
    double x =15.5683,y =34267.1;
    cout<<x<<" "<<y<<"\n"; //15.57  3.427e+04

    //shoepoint - show trailing zeros. even if no zero in variable after decimal add some
    //noshowpoint reverts it
    //showpos - shows + sign for positive values. noshowpos reverts it
    //uppercase - prints 'e'as'E'. nouppercase reverts it 

    double z=1.23;
    cout<<std::showpoint<<z<<"\n";//1.230
    cout<<std::showpos<<z<<"\n";//=1.230
    cout<<std::uppercase<<y<<"\n";//+3.427E+04
    return 0;
}