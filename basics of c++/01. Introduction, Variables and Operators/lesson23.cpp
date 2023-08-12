//floating point(default printing format)

#include <iostream>

using namespace std;

int main(){
    //no trailing zeros after decimal zeros removed
    double x =1.2300;
    cout<<x<<"\n"; //1.23
    //precision means total digits(excluding the digits used after e)
    //default precision value is 6 
    double y = 1567.56732;
    cout<<y<<"\n";//1567.57
    double z = 1244567.45;
    cout<<z<<"\n"; //1.24456.67
    double w = 124456.67;
    cout<<w<<"\n"; // 124457
    double u = 123e+2;
    cout<<u<<"\n";//12300
    return 0;
}