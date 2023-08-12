// floating point 
//fixed and scientific see notes
//precision is different then before it means digits after decimal point

#include <iostream>
#include<iomanip>
using namespace std;

int main(){
    double x = 1.23,y=1122456.453;
    cout<<std::fixed;
    cout<<x<<"\n" //1.230000 as 6 precision after decimal
        <<y<<"\n"; // 1122456.453000

    cout<<std::setprecision(2);
    cout<<x<<"\n" //1.23 as 2 precision after decimal
        <<y<<"\n";//1122456.45 before decimal not considered in precision for fixed

    double z = 1.2e+7;
    cout<<z; //12000000.00

    cout<<std::scientific;
    cout<<x<<"\n" //1.230000 e+00 as 6 precision after decimal
        <<y<<"\n";//1.122456e+06

    cout<<std::setprecision(2);
    cout<<x<<"\n" //1.23 e+00 as 2 precision after decimal
        <<y<<"\n";//1.12e+07 all go to e and precision 2 decimal only

    double z = 1.2e+7;
    cout<<z; //1.20e+07


    return 0;
}