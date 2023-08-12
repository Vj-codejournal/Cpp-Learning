#include <iostream>

using namespace std;
class a{};
class b{};
class c:public a,public b {};
int main(){
    
    return 0;
}

//solun of dimond probleem

#include <iostream>

using namespace std;
class A{
    public:
    int x;
    //A(int a):x(a){};
    A() {cout<<"hi";}
};
class B : virtual public A { };
class C: virtual public A { };
class D:public B,public C { };
int main(){
    D d;
    cout<<d.x;
    return 0;
}