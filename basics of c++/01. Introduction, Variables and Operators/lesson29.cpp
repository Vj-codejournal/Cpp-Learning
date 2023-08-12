//Logical operators
#include <iostream>

using namespace std;

int main(){
    int x =10,y =20;
    bool res1 = (x>0 && x<100);
    cout<<res1<<"\n";//1
    bool res2 = (x>0 and x<100); //and also valid in place of &&
    cout<<res2<<"\n";//1
    bool res3 = (x>0 || x>y);
    cout<<res3<<"\n";//1
    res3 = !res3;
    cout<<res3<<"\n"; //0 

    //see notes
    bool res4 = (x<20) || (x++); // in or if 1st part is true stop as output will be true not depending on 2nd part so not evaluate 2nd part
    cout<<res4<<"\n";//1
    cout<<x;//10

    bool res5 = (x>10) && (x++);//first part is false so it stop there not evaluate the 2nd part
    cout<<res5;
    cout<<x;
    
    bool res6 = (x==9) || (x++);
    cout<<res6<<"\n";//1 true as 1st is false but 2nd x++ is a non zero int so true and 2nd part processed so increament happen
    cout<<x;//11

    return 0;
}