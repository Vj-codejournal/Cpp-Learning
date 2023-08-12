// #include <iostream>
// #include <cmath>
// using namespace std;

// int main(){
//     int n;
//     cout<<"Enter the number of digits in binary\n";
//     cin>>n;
//     int arr[n];
//     int decimal =0; 
//     for(int i=0;i<n;i++){ // 1011  enter 1 1 0 1
//         cin>>arr[i];
//     }
//     for(int i = 0;i<n ;i++){
        
//         decimal += arr[i] * pow(2,i); 
//     }
//     cout<<decimal;
//     return 0;
// }


// #include <iostream>
// #include <cmath>
// using namespace std;

// int main(){
//     int n;
//     cout<<"Enter the number of digits in binary\n";
//     cin>>n;
//     int a;
//     int decimal =0; 
//     cout<<"Enter the digits of the binary one by one from right\n";
        
//     for(int i=0;i<n;i++){ // 1011  enter 1 1 0 1
//         cin>>a;
//         decimal += a*pow(2,i);
//     }
    
//     cout<<decimal;
//     return 0;
// }

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int val=0;
    int base =1;
    while(n>0){
        int last_digit = n%10;
        val = val + (last_digit*base);
        n=n/10;
        base = base*2;

    }
    cout<<val;
    return 0;
}