#include <iostream>
#include<cmath>
using namespace std;
int floorSqrt(int n)
{
   int arr[n] = {0};
   int start = 0;
   int end = n-1;
   int mid = start + (end - start) /2;

   while(start <= end){
    if(pow(mid,2) == n || (pow(mid,2) < n && pow(mid+1,2)> n)){
        return mid;
    }
    
    if(pow(mid,2)> n){
        end = mid - 1;
    }
    else{
        start = mid+1;
    }
     mid = start + (end - start) /2;
   }
   
}

double morePrecision(int n,int precision ,int tempSol){
    double factor = 1;
    double ans = tempSol;
    for(int i = 0;i<precision ;i++){
        factor= factor/10;

        for(double j = ans;j*j<n;j = j+ factor){
            ans = j;
        }
    }
    return ans;
}
int main(){
    int n;

    cin>>n;

    int tempSol = floorSqrt(n);

    cout<<morePrecision(n,3,tempSol);
    return 0;
}

//to find exact square root
//get base number from here 
//eg 6 then see 6.1^2 <37 true 6.2^2 <37 true 6.3^2 <37 false so see 6.21 and so on