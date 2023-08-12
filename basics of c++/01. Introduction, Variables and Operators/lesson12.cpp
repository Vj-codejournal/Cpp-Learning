//floating point literals


#include <iostream>

using namespace std;

int main(){
    float a =10.5f; //float
    double b = 10.525; //if no suffix treat as a double
    float c = 2.1e15f; //2.1 x 10^15
    double d = 200.1e-80; //200.1 x 10^-80
    double f = 0x1A.1p2;//  1A give 26 , .1 is 1/16 = 0.0625 , p2 means 2^2 so 26.0625 X2^2
    return 0;
}