//constructors

#include <iostream>

using namespace std;
class point{
    private:
    int x,y;
    public:
    point(){//constructor initialize  x and y to 0
        x=0;
        y=0;
    }
    point(int x1,int y1){//initialize x and y to x1 and y1
        x = x1;
        y = y1;
    }
    void print(){
        cout<<x<<" "<<y<<endl;
    }
};
int main(){
    point p1,p2(10,20);//p1 without any parameter so go to x =0 and y =0 as that has no parameter p2 has parameter so go to 2nd one
    p1.print();
    p2.print();

    point *ptr = new point(5,10);//dynamically allocated new point
    ptr -> print();
    return 0;
}

//initializer list

// class point{
//     private:
//     int x,y;
//     public:
//     point(): x(0),y(0){ } in this write member name then in bracket () initalize them
//     point(int x1,int y1): x(x1),y(y1)
//     {
//     }
//     void print(){
//         cout<<x<<" "<<y<<endl;
//     }
// };