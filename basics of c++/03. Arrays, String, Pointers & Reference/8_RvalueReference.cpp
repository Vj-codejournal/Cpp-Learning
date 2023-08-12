//L value and R value reference
//till here seen l value reference
//l value refers to a memory location that identifies an object 
//r value reffers to the data value that is stored at some address in memory
//r value use &&
// literals like "user" or results of expressions like x+y are r values cannot be pass to a function be & l values method of reference
//const l value and r value reference used here

#include <iostream>

using namespace std;
void fun (string &&s){//if single & not compile
    s = "hi" + s;//as && so can modify too if used const then cant modify
    cout<<s;
}
int main(){
    fun("user");//user is literal here not passed by single &
    return 0;
}

//int &x =3; invalid
//const int &x = 3; now valid
//int &&x = 3; valid

//string &s = "Gfg"; invalid
//const string &s = "Gfg"; valid
//string &&s = "Gfg"; valid