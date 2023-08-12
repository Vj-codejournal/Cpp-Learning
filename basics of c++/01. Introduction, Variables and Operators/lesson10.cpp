//literals
/*no preffix - decimal 
0x -hexadecimal in this we have digits from 0 to 9 the  digits from a to f treated like 10 to 15
so if 0x1A start from right A is 10 and 16 ^0 mul to it the 1 mul by 16^1 and so on 
so we get 10x16^0 + 1x16^1 =26
0 -octal  prefix by 0 in octal 0 to 7 only allowed if 016 start from right and mul digits by increasing power of 8
so if 016    6x8^0 + 1x8^1 = 14
0b -binary in binary is 0 and 1 only start from rigt mul by increasing power of 2 
so 0b11  1x2^0 + 1x2^1 = 3*/


#include <iostream>

using namespace std;

int main(){
    int a =20;
    int b = 0x1AF;
    int c = 016;
    int d = 0b11;
    cout<<a<<"\n"
        <<b<<"\n"
        <<c<<"\n"
        <<d;
    return 0;
}
