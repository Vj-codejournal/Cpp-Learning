/*Type conversion 
it lets us convert int to double or float and other forms vice versa without typecasting
but this conversion might cause loss of info
float x = 10.5
int y = x; // y =10
boal z =y // z = true as non zero values true in boalean and 0 is false*/

#include <iostream>

using namespace std;

int main(){
    int a =-1;
    unsigned int b=a; //4292967295 output as converted to largest unsigned value
    int c =-2;
    unsigned int d =c; //4292967294 output as converted to second largest unsigned value and this goes so on
    

    int x = 10;
    char y ='A'; // when added automatically updated to int  as char come before int in the order and A ascii value is 65 so 10 +65
    cout<<(x+y)<<"\n";
    float z=5.5;
    cout<<(x+y);
//this was implicit conversion did by compiler itself
    return 0;
}