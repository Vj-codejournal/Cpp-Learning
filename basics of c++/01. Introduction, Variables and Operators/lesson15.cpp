//implicit vs explicit conversion
#include <iostream>

using namespace std;

int main(){
    //implicit
    int x =15 , y=2;
    double z =x/y;
    cout<<z;

    //explicit c style
    int a =15 , b=2;
    double c = double(x)/y; //if numerator is float after div also float seen in C
    cout<<c;

    //c++ style explicit conversion
    int e =15 , f=2;
    double g = static_cast<double>(e)/f;
    cout<<c;

    return 0;
}