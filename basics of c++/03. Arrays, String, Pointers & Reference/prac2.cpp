#include <iostream>

using namespace std;

int main(){
    int n,count=0;
    cin>>n;

    int arr[n];

    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0; i<n;i++){
        if(arr[i] == 'n'){
            continue;
        }
        else{
            for(int j=i+1;j<n;j++){
                if(arr[i] == arr[j]){
                    arr[j] = 'n';
            }
        }
    }
    }
for(int i = 0; i<n;i++){
        if(arr[i] != 'n'){
            count++;
        }
    }    
    cout<<count;
    return 0;
}

//GFG method
//check to left of the current position of arr if dont have any repeat count increase other wise dont
// #include <iostream>

// using namespace std;
// int distinct(int arr[], int n){
//     int count=0;
//     bool isDistinct = true;

//     for(int i =0 ;i <n;i++){
//         isDistinct = true;

//         for(int j =i-1;j>0;j--){
//             if(arr[i] == arr[j]){
//                 isDistinct = false;
//                 break;
//             }
//         }
//         if( isDistinct == true){
//             count++;
//         }
//     }
//     return count;
// }
// int main(){
//     int n;
//     cin>>n;

//     int arr[n];

//     for(int i = 0; i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<distinct(arr,n);
//     return 0;
// }