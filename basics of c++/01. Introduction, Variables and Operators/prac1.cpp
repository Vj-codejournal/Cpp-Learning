//Find the last digit of a number
//input n = 123, -352, 1049 
#include <iostream>

using namespace std;

int main(){
    int x = -235;
    int ans = abs(x)%10; //abs remove -ve absolute value
    cout<<ans;
    return 0;
}

//solun div by 10 remaider is the last digit