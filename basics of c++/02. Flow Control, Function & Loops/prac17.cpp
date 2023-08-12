#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a=0;
    for(int i = n+1;;i++){
        for(int j=2;j<i;j++){
            if(i%j ==0){
                a=1;
                break;
            }
            
        }
        if(a==0){
            cout<<"Next prime no is "<<i;
            break;
        }
        else{
            a=0;
        }


    }
    return 0;
}


// #include <iostream>

// using namespace std;

// int nextPrime(int n){
//     n++;
//     while(true){
//         int i;
//         for(i = 2;i < n;i++){
//             if(n % i == 0)
//                 break;
//         }
//         if(i == n)return n;
//         n++;
//     }
// }


// int main(){
//     int n;
//     cin>>n;
//     cout<< nextPrime(n);
//     return 0;
// }