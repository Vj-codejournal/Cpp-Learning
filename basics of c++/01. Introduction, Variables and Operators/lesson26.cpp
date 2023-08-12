//Arithmetic Operators 
#include <iostream>

using namespace std;

int main(){
    int x = 20,y = 10;
    cout<<(x+y)<<"\n"
        <<(x-y)<<"\n"
        <<(x%y)<<"\n"
        <<(x*y);

    int a = 10;
    int b = a++; // b=a and then x = x+1
    int c = ++a; // a = a+1 then c =a a first become 11 then c =a so =11    
    return 0;
}

/*+,-, *,/ work for int and float both but % only valid for int

 % tells the remainder
sign of a%b is same as a
cout<<(10% -3) == 1
cout<<(-10% 3) == -1

a/b and a%b is undefined when b is zero  give error
a +ve and b 0 then a/b is infinite,, a-ve and b 0  then it is - infinite
*/

