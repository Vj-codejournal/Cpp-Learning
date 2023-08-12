//Default argument in function
#include <iostream>

using namespace std;

void printDetails(int id,string name="NA",string address ="NA")// default vlue of name is set as NA for int can set 0 as default and so on 
{
    cout<<"Id is "<<id<<"\n";
    cout<<"Name is "<<name<<"\n";
    cout<<"Address is "<<address<<"\n";
    
}

int main(){
    printDetails(101,"Sandeep","Noida");
    cout<<"\n";
    printDetails(201,"shiram"); // address not given default come NA
    cout<<"\n";
    printDetails(301);

    return 0;
}