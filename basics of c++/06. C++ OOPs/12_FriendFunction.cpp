#include <iostream>

using namespace std;
class Employee;

class Printer{
    public:
    void printEmp(const Employee &e);
};
class Employee{
    private:
    int id;
    string name;
    public:
    friend void Printer::printEmp(const Employee &e); // now printEmp function can access all private element of class Employee
    Employee(int i,string n): id(i), name(n){};
};
void Printer ::printEmp(const Employee &e){
    cout<<e.id<<" "<<e.name<<" ";
}//this defined after declaring its presence in employee class
int main(){
    Printer p;
    Employee e(101,"ABC");
    p.printEmp(e);
    return 0;
}