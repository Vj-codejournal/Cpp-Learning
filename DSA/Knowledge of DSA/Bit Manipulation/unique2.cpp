#include <iostream>

using namespace std;
int setBit(int n,int pos){
    return ((n & (1<<pos)) != 0);
}
int unique(int *arr,int n){
    int xorsum = 0;
    for(int i = 0;i<n;i++){
        xorsum = xorsum^arr[i];
    }//get 7^5 = 0010 finally
    //now have to get right most set bit that is 1
    int tempxor = xorsum;
    int setbit = 0;
    int pos =0;
    while(setbit = xorsum & 1){
        setbit = xorsum & 1;//if the right most digit 1 get 1 else 0
        pos++;
        xorsum = xorsum >> 1;

    }
    int newxor = 0;
    for(int i = 0;i<n;i++){
        if(setBit(arr[i],pos-1)){
            //if at that pos have 1 the do xor of it with other //like this see for all elements of array
            newxor = newxor^arr[i];//get 7 here 
        }//while loop pos++ one extra so do pos - 1
    }

    cout<<newxor<<endl;//7
    cout<<(newxor^xorsum)<<endl;//7^7^5 ==> 5

}
int main(){
    int arr[] = {2,4,6,7,5,4,6,2};

    unique(arr,8);
    return 0;
}