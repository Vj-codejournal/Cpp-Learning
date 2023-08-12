//copy constructor - when create an object from existing object 
#include <iostream>

using namespace std;
class Test {
    int *ptr;
    public:
    Test(int x){
        ptr = new int (x);
    }
    //for deep copy
    Test (const Test &t){// called by reference as if not it will again have to make a copy for call by value so again call copy constructor endless cycle
        int val = *(t.ptr);//value at t1 taken
        ptr = new int (val);//new memory created for t2 now change in t2 not refrected in t1 as different address for both
    }
    void set(int x){
        *ptr = x;
    }
    void print(){
        cout<<*ptr<<" ";
    }
};
int main(){
    Test t1(10);
    Test t2(t1);//same as writing Test t2 = t1 //initialized t2 same as t1
    //default constructor of class does shallow copy as when ptr in class copy is created of ptr and its value to copy it to t2 and new memory not allocated to t2 so t2 change also change t1
    //not same as Test t2; t2= t1; as t2 already initialized by default constructor of test class
    t2.set(20);
    t1.print();
    t2.print();//give 20 20 should be 10 20 

    //this is need of creating own copy constructor in class //deep copy
    Test t2(t1);
    t2.set(20);
    t1.print();
    t2.print();//this will give 10 20 output
    return 0;
}