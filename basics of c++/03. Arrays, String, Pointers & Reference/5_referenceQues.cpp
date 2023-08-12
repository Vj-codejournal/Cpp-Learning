//Q1
#include <iostream>

using namespace std;

int main(){
    int x =10,z=20;
    int &y = x;//now x and y point same thing
    y =z;//both x and y are assigned z from here
    y = y+5;
    cout<<x<<" "<<y<<" "<<z;//25 25 20
    return 0;
}

//Q2
#include <iostream>

using namespace std;
int &fun(){//this function returns reference so even if x is local variable actual reference return *** so here z can mordify x also a local variable 
//dont do this to non static var as they dont exist after function call over so create problem
    static int x =10;
    return x;
}
int main(){
    int &z = fun();
    cout<<fun()<<" ";
    z =30;//z and fun both become 30 (x is changed)
    cout<<fun();
    return 0;
}
//10 30

//Q3
#include <iostream>

using namespace std;

int main(){
    string s1 = "GfG ",s2 = "Courses";
    string &&s3 = s1+s2;//&& can refer to r values and s1 s2 are r values
    s3 = "Welcome to " + s3;
    cout<<s3;
    return 0;
}