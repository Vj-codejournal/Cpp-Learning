#include <iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter a numer\n";
    cin>>n;
    
    for(int x =2;x<=n;x++){
        
        while(n%x==0){
            cout<<x<<" is a prime factor of "<<n<<"\n";
            n = n/x;
            x=2;
        
        }
        
        
    }
    return 0;
}


// #include <iostream>

// using namespace std;

// int main(){
//     int num = 355;
//     int i =2;

//     while(i <= num){
//         if(num % i ==0){
//             printf("%d\n",i);
//             num =num/i;
//             i=2;
//             continue;
//         }
//         i++;
//     }
//     return 0;
// }


// -----------------------------------------------------
// method 3

// #include <iostream>

// using namespace std;

// int isPrime(int n){
//     for(int i =2;i<n;i++){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }

// void prime_factors(int n){
//     for(int i = 2;i<= n; i++){
//         if(isPrime(i)){
//             int x = i;
//             while(n%x == 0){
//                 cout<<i<<" ";
//                 x= x*i;
//             }
//         }
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     prime_factors(n);
//     return 0;
// }