#include <iostream>

using namespace std;
int setBit(int n,int pos){
    return ((n & (1<<pos)) != 0);
}
int unique(int *arr,int n){
    int xorsum = 0;
    for(int i = 0;i<n;i++){
        xorsum = xorsum^arr[i];
    }//getthe xor of the two distinct numbers 7^5 = 0010 ,finally we get 1 at all the places where the bits are different in 7 and 5
    //and if both nums are different there would at be one bit that is differnt so get atleast 1 one in their xor


    //now have to get right most set bit that is 1
    //(num & num-1) ^ num give the right most set bit that is 1

    //get set bit at index 1 so in 14 and 4 case 14 has 1st position as 1 and 4 has 1st position has 0 so can seperate on basis of this in two buckets

    //[2,4,2,14,3,7,7,3] can see 2 is 10 so 1st bit is 1 so in bucket with 14 , 14 2 2 3 3 7 7 in one bucket and 4 in other so final 14 and 4 left in two bucket

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

/*

int xorsum = 0;
    for(int i = 0;i<n;i++){
        xorsum = xorsum^arr[i];
   }
//get set bit
rightmost = (xorsum & xorsum-1) ^ xorsum

//make two bucket
b1 = 0 b2 = 0
//if we do set bits & with  number and give non zero than in that bucket b1
eg set bit is 10
so for 5 
100
  10 &
000 so go in b2
for(int i = 0;i<n;i++){
if(arr[i] & rightmost != 0){
b1 = b1^arr[i];
}
else{
b2 = b2^ arr[i];
}}

so final will get two numbers in different buckets

take long for xorsum as xorsum if -2^31 then -1 to it overflow in int

*/