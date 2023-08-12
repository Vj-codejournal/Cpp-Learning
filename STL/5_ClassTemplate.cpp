#include <iostream>

using namespace std;
template<typename T>
struct Pair{
    T x,y;
    Pair(T i, T j){x = i; y = j;}
    T getFirst(){return x;}
    T getSecond(){ return y;}
};

int main(){
    Pair<int>p1(10,20),p2(30,40);
    cout<<p1.getFirst()<<" "<<p1.getSecond();

    return 0;
}


//to declare a function outside a  class template,here class name is pair
// C++ program to illustrate
// Class Templates
#include <iostream>
using namespace std;

// T is the variable and
// can be extended to multiple types
template <typename T>

// A structure can also be used
// instead of a class as it has
// public access type
struct Pair {

    // These pairs can be of any type
    T x, y;

    // Constructor accpecting both
    // parameters of same type
    Pair(T i, T j)
    {
        x = i;
        y = j;
    }

    // Function of T type
    T getFirst();

    // Function of T type
    T getSecond()
    {
        return y;
    }
};

template <typename T>

Pair<T>::getFirst()
{
    return x;
}

// Drivers Method
int main()
{

    // Pair needed to be passed
    Pair<int> p1(10, 20);
    cout << p1.getFirst() << " "
         << p1.getSecond();
    return 0;
}