#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int N;
    cout<<"enter the no. N\n";
    cin>>N;
    for (int i = 1; i <100; i++)
    {
        
        if(((int)(N/pow(10,i)))==0){ // as pow give double so 344/1000 is 0.344 not 0 so typecast to int
            cout<<"the no. of digits in"<<N<<"is"<<i;
            break;
        }
        
    }
    
return 0;
}