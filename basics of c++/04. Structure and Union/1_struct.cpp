#include <iostream>

using namespace std;
typedef struct point //like int now point also a new data type
{
    int x;//in memory also x stored first then y
    int y;
}P;//typedef used now 'struct point' replaced with P (struct P p) but can still use point but no need of this as in c++ we can directly write point no need to write struct point

struct Student
{
    int rollNo;
    string name;
    string address;
};
int main(){
    struct point p; //writing struct here is optional in c++ but mandatory in c
    p.x = 10;
    p.y = 20;
    cout<<p.x<<" "<<p.y<<endl;

    Student s = {101,"ABC","XYZ"};//write in same order as declared in struct student for any order see below//if dont initialize any value at allthen dont get 0 get some random value
    cout<<s.rollNo<<" "<<s.name<<" "<<s.address<<"\n"; 
    //Student s2 = {.address= "sds",.name = "afe"};//also used to skip a input here roll no bydefault get 0//only for c program
    return 0;
}

//c++ has class so mostly no use of struct