//input in C++ part 2
#include <iostream>

using namespace std;

int main(){
    int x,y;
    cout<<"Enter Two Integers:\n";
    cin>>x>>y;//can take multiple output, chained input
    cout<<"sum is"<<(x+y);

    string name;
    cout<<"Enter your name:\n";
    getline(cin,name);
    cout<<"Welcome"<<name;
    return 0;
}

/*For input can do both ways
 x y use space in betwn while entering
 or x
    y use enter key both store the same way

This space thing cause problem in multiple words string because it will 
take the first word only to store in first variable as after space consider 
as different input so use getline  */ 
