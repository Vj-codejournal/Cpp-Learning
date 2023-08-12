#include <iostream>

using namespace std;
//funtion template
template<typename T>//can use class in place of typename //T take datatype as parameter can name it anything 
T myMax(T x , T y)//so here return datatype is T and x & y also T datatype
{
    return (x>y)?x:y;
}
#define myMax2(x,y) ((x>y)?(x):(y)) 
int main(){
    
    cout<<myMax<int>(3,7)<<endl;//int is passed in template and it create a function with int everywhere to be used 
    cout<<myMax<char>('c','g')<<endl;
    cout<<myMax2(3,7)<<endl;
    return 0;
}

//in my defined class have to make sure that > is overloded for it to work

//template
// template<typename T>
// T myMax(T x , T y)
// {
//     return (x>y)?x:y;
// }

//macro

//#define myMax2(x,y) ((x>y)?(x):(y)) // # pre processer replaces myMax everywhere in main with right side function