#include <iostream>

using namespace std;
class complex{
    private:
    int real,imag;
    public:
    complex(int r = 0,int i = 0): real(r),imag(i){ }
    complex operator+(complex const &obj){//made the addition function for our own data type
            complex res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;
            return res;
    }
    void print(){ cout<<real<<" + i "<<imag<<endl;}
};
int main(){
    complex c1(10,5),c2(2,4);
    complex c3 = c1 + c2;//operator+ used c1>operator+(c2) so real is c1 real part andd obj real is c2 real part
    c3.print();
    return 0;
}
//can define operator + globally too 