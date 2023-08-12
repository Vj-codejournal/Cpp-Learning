//output in c++
#include <iostream>


using namespace std;

int main(){
    cout<<"GeeksforGeeks";
    cout<<" "<<"Courses"; // << can be used multiple times
    int x =10;
    bool b = true;
    float f =10.5f;
    string s ="GfG";
    cout<<x<<" "<<b<<" "
        <<f<<" "<<s<<endl; //endl used to create new line on the screen also can use "\n"
                        // difference is endl also flushes the output stream so that buffer flush reduce other wise \n faster use that
    cout<<(10*5)<<" ";
    cout<<'g';
    return 0;
}
//c++ also allows to use cout for user defined data types like structure created eg student it has name is passed can also be printed