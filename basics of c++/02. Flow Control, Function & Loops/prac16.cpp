#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a;
    int j=0,i=0;
    int arr[j];

    while(n>0){
        a = n%2;
        n = (n-a)/2;
        j++;
        arr[i] = a;
        //cout<<arr[i];
        i++;
    }
    //do same by pointer if stored at 0th position then shift it to next postion and store the next term at 0th position
    
    for(int z=j-1;z>=0 ;z--){ //j-1 as j is here a position if 5 elements for input 18 then 4th is the last position of array .that is why if start from z=j at that position give garbage value
        cout<<arr[z];
    }
    return 0;
}

//in video done by vector see later

//this array version failed for big number check acc to it array size dont change after initialisation