#include <iostream>

using namespace std;
class base{
    protected:
    int x;
    public:
    base(int a): x(a){cout<<"base\n";}
};
class derived :public base{
    private:
    int y;
    public:
    //derived(int b): y(b){cout<<"derived\n";}
    //give error as base also part of it should its variable/objects should also be initialized (constructor) again as we have created a int x wala base variable and not given it value it throw error 
    //if base had a no int default constructor then no error but here error will come
    //call parametrized constructor of base class using initializer list
    derived(int a,int b): base(a),y(b){cout<<"Derived\n";}
    void print(){cout<<x<< " "<< y<<endl;}
};
int main(){
    derived d(10,20);
    d.print();
    return 0;
}

//if derived inherit from base and did not initialized base variable int x then it will go for default constructor of base class that it constructor with no int x and if it is not present then throw error