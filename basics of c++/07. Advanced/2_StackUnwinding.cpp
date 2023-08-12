#include <iostream>

using namespace std;
void f1()throw(int){//mentioned above with function that it has a chance to throw 
    cout<<"f1 begins \n";
    throw 100;
    cout<<"f1 ends \n";
    
}
void f2()throw(int){
    cout<<"f2 begins \n";
    f1();
    cout<<"f2 ends \n";
    
}
void f3(){ 
    cout<<"f3 begins \n";
    try{
        f2();
    }
    catch(int i){
        cout<<"caught exception\n";
    }
    cout<<"f3 ends \n";
    
}
int main(){
    f3();
    cout<<"bye";
    return 0;
}