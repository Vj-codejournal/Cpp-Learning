#include <iostream>

using namespace std;
class point{
    //public: this will make it public
    int x;
    int y;
};
int main(){
    point p;
    //p.x = 10;//class has all the memberr private by default cant access by . throw error in struct can access with .
    //cout<<p.x;

    return 0;
}

//we can make thinks public in class but also make things private in a struct


#include <iostream>

using namespace std;
struct point{
    private://now make private cant access by . also similar write public: in class
    int x;
    int y;
};
int main(){
    point p;
    // p.x = 10;
    // cout<<p.x;

    return 0;
}


#include <iostream>

using namespace std;
struct Point{
    int x;
    int y;
    Point(int a,int b){
        x =a; y =b;//constructor - initialize value of x and y
    }
    void print(){//declared a function in struct
        cout<<x<<" "<<y<<endl;
    }
};
int main(){
    Point p(10,20);
    p.print();
    return 0;
}

 


//struct and class differ in inheritence also.default for struct public and class is private

#include <iostream>

using namespace std;
class Base{
    public://base class has public member x
    int x;
};
class Derived : Base {};//derived inherits from base class //as inherited a class and not mentioned public or private by default it make derived as private //add public before base here then d>x can be accessed 
int main(){
    Derived d;
    //d.x = 20;
    return 0;
}



#include <iostream>

using namespace std;
struct Base{
    public://base class has public member x
    int x;
};
struct Derived : Base {};//derived inherits from base struct //as inherited a struct and not mentioned public or private by default it make derived as public 
int main(){
    Derived d;
    d.x = 20;
    return 0;
}

