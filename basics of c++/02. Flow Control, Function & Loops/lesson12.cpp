#include <iostream>

using namespace std;
void print(string s){
    cout<< s<<"\n";
}
void print(int x){
    cout<< x<<"\n";
}
void print(char c){//if this removed then in main char wala int se match ho jayga aur uski ascii value save ho jaygi
    cout<< c<<"\n";
}
//above 3 function use same logic just data type different can use template for this only.for different logic and parameters only use function overloading
int main(){
    print('a');
    print(10);
    print("GfG");
    return 0;
}