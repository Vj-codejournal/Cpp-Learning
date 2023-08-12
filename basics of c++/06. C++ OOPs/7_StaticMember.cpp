//in a online game to keep track of how many player in game we can do when each object of player class made count ++ and when destructed count --(to leave the game)
//make a static global variable that keeps the count
#include <iostream>

using namespace std;
class Player{
    public:
    static int count;
    Player(){count++;}
    ~Player(){count--;}

};
//static member defined like this outside the class
int Player :: count = 0;
int main(){
    Player p1;
    cout<<Player::count<<" ";//1//can do p1.count or p2.count access same variable as static variable shared accross all objects of class so static members also called class members
    Player p2;
    cout<<Player::count<<" ";//2

    

    return 0;
}


// #include <iostream>

// using namespace std;
// class Player{
//     private:
//     static int count;
//     public:
    
//     Player(){count++;}
//     ~Player(){count--;}
//spl static member functions to mordify them not preffer to use normal function
//     static int getCount(){ return count;}//now can only use this to access count

// };
// //static member defined like this outside the class
// int Player :: count = 0;
// int main(){
//     Player p1;
//     cout<<Player::getCount<<" ";
//     Player p2;
//     cout<<Player::getCount<<" ";

    

//     return 0;
// }