//why preffer initializer list
#include <iostream>

using namespace std;
class Test{
    public:
    Test(){cout<<"Default\n";}
    Test(int x){cout<<"Parametrized\n";}
};
class Main{
    Test t;//here constructor of test will initialize test() case so get default
    public:
    // Main()//construct of main
    // {
    //     t = Test(10);//then here constructor will initialize test(int ) case so parametrized
    // }
    //use initializer list
     Main(): t(10) //initialized once only so now parametarized only print
    {
        
    }
};
int main(){
    Main m;  //as t is of test(int ) for default should not have come for this but as test t initalized above this happen in normal constructor not in initilizer method
    //it happens because Main constructor body is called after Test t happen 
    return 0;
}