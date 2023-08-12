#include <iostream>

using namespace std;
class test{
    public:
    test(){cout<<"constructor called\n";}
    ~test(){cout<<"destructor called\n";}//only one destructor in a class to destroy after it went out of scope {}
};
int main(){
    {
        //test t1; //as this scope {} end after t1 is called it is destroyed again
    }
    //test t2;
    return 0;
}

#include <iostream>

using namespace std;
class test{
    int x;
    public:
    test(int i): x(i){
        cout<<"cons"<<x<<endl;}
    ~test(){
        cout<<"cons"<<x<<endl;}
    
};
int main(){
    
    test t3(10);
    test t4(20);
    //multiple objects in same scope destructed in reversre order of there creation 10 created then 20 so 20 destroyed first then 10
    return 0;
}
//like new there is delete to dynimacially delete memory this is when destructor is called

//default destructor dont remove dynamically created memory so have to create a delete destructor for them