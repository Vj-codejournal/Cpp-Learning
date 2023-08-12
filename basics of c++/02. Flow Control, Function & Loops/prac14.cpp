//prime number checker
#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int prime =0;

    for(int i = 2;i< n; i++){
        if(n%i==0){
            prime =1;
            break;
        }
    
    }
    if(prime ==1){
        cout<<"it is not a prime number";
    }
    else{
        cout<<"it is a prime number";
    }

    return 0;
}

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n ==0 or n==1){
        cout<<"Neither Prime nor composite";
        return 0; // end here
    }



    int i =2;
    while(i<n){
        if(n%i==0){
            cout<<"no";
            return 0;
        }
        i++;
    }
    cout<<"yes";
    return 0;
}