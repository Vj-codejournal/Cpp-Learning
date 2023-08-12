//function overloading

#include <iostream>

using namespace std;

int myMax(int x,int y){
    return (x>y)? x:y;
}
int myMax(int x,int y,int z){
    return myMax(myMax(x,y),z);//here myMax(x,y) will go to upper function according to its variable even though function name same
}
int main(){
    int a = 10,b = 30,c = 5;
    cout<<myMax(a,b)<<"\n";
    cout<<myMax(a,b,c)<<"\n";
    
    return 0;
}