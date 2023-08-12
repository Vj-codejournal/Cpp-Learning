//switches
#include <iostream>

using namespace std;

int main(){
    int x=0,y=0;
    cout<<"Enter a move\n";
    char move;
    cin>>move;
    switch(move)//acc to this variable "move" multiple branches will be made
    {
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        default: cout<<"invalid input";
    }
    cout<<x<<" "<<y;
    return 0;
}