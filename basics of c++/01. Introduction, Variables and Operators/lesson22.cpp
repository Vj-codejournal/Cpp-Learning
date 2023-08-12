//Formating Manipulation
#include <iostream>
#include<iomanip>

using namespace std;

int main(){
    int a=12;
    cout<<std::setw(5);
    cout<<std::setfill('*');
    cout<<a<<"\n";
    cout<<"hi"<<"\n";//***hi
    cout<<std::left; //if extra spaces then of use to align
    cout<<std::setw(5);
    cout<<a;//12***


    return 0;
}