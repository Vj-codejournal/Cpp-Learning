//OOPs
//examples

#include <iostream>

using namespace std;
class complex{
    private:
    int real;
    int imag;

    public:
    void print(){
        cout<<real<<" + i "<<imag<<endl;//this function can access private element as still inside class.main function cant
        }
        complex(int r,int i){//same as initial class - constructor - used to initialize variable in object //if we take many student name and decide no special char in then can use this to impliment in all
            real =r;
            imag =i;
    }
};
int main(){
    complex c1(10,15);
    c1.print();
//if c1.real here throw error as private
    return 0;
}