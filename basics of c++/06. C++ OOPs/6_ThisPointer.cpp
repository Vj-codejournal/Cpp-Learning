#include <iostream>

using namespace std;
class point{
    int x, y;
    public:
    point (int x1,int y1){
        x = x1; //this -> x = x1 //this pointer point to the object for which this function 
        y = y1; //this -> y = y1
    }
    // point (int x,int y){//before it would have collided with member name not now
    //     this -> x = x; 
    //     this -> y = y;
    // }

    //chaining of function
    point &setX(int x){
        this -> x = x;
        return *this;

    }
    point &setY(int y){
        this -> y = y;
        return *this;

    }


};
int main(){
   point p1(10,20),p2(5,5); //both have there own copy of x and y but use same constructor they dont interchage due to 'this' pointer

   p1.setX(5).setY(5); //if want to change x and y both but should be of same object as then only this pointer same//first setX happen but it got a hold of its this ptr so for y also go to the same object and get its y

   //used to chain couts
   //cout<<x<<y;//insertion << operator function does chaining same way can see first called x it return this pointer to object can print y
    return 0;
}