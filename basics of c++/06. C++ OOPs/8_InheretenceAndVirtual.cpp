#include <iostream>

using namespace std;
class Person{
    protected:
    string name;
    int id;
};
class Student: public Person{//format of inheritance //public is access specifier
private:
int marks;
public:
void print(){
    cout<<name<<id<<marks;
}
};
int main(){
    
    return 0;
}

//virtual functions

#include <iostream>

using namespace std;
class Parent{ };
class child : public Parent{};


int main(){
    
    Parent * p = new child; // ptr is of base type and points to derived type
    //reference also work
    child c2;
    Parent &p2 = c2;
    return 0;
}


#include <iostream>

using namespace std;
class Parent{
    public:
    void print(){ cout<<"Base\n";}
    //virtual void print(){ cout<<"Base\n";}
 };
class child : public Parent{
    public:
    void print(){ cout<<"Derived\n";}
    //void print() override { cout<<"Derived\n";}
    //when it over ride a virtual function can use to increase readibility


};


int main(){
    Parent p;
    child c;
    p.print();
    c.print();
    Parent * ptr = &c;//this base pointer point to derived class so when call the function call it of derived class only 
    //////that should have happened but actully base type ptr so call the print function of base
    /// to correct use virtual keyword 
    //this is called function overwriting. base class is overwrited by derived as function name is same
    //this is run time polymorphism
    ptr->print();
    return 0;
}