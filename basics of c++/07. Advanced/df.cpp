#include<bits/stdc++.h>

int main()
{int t;
std::cin>>t;
while(t--){
    int arr[100];
    int n;
    std::cin>>n;

    for(int i = 0; i<n; i++){
        int temp;
        std::cin>>temp;
        arr[i]= temp;
    }

    for(int i = 0; i<n; i++){
        int first = arr[0];
        int second = arr[1];

        if (first==second)
        {
            int to_compare = first;
            
            if (arr[i]!=to_compare)
            {
                std::cout<<i+1<<std::endl;
                break;
            }
            else{
                continue;
            }
        }
        
        
        else{
            int third = arr[2];
            if(first == third){
                std::cout<<1+1<<std::endl;
                break;
            }
            if(first == second){
                std::cout<<2+1<<std::endl;
                break;
            }
            else if(second==third){
                std::cout<<0+1<<std::endl;
                break;
            }
            

        }
        
    }
}
return 0;
}


// #include<bits/stdc++.h>
// int main(){
 
// long long int count=0,n,k;
 
// std::cin>>n>>k;
   
// for (int i = 1; i <= n; i=i+2)
// {
    
//         count++;
    
//      if (count==k)
//         {
//             /* code */
//             std::cout<<i;
//             break;
//         }
// }
// if (count!=k)
// {
//     /* code */
// for (int j = 2; j<=n; j = j+2)
// {
    
    
//        count++;
   
//     if (count==k)
//         {
//             /* code */
//             std::cout<<j;
//             break;
//         }
        
// }
// }
 
// return 0;
// }
//  #include<bits/stdc++.h>

// int main() {
//     long long int n, k;
//     std::cin >> n >> k;

//     if (k <= (n + 1) / 2) {
//         // kth number is odd
//         std::cout << (2 * k) - 1;
//     } else {
//         // kth number is even
//         std::cout << 2 * (k - ((n + 1) / 2));
//     }

//     return 0;
// }
//1000000000000 500000000001

//  #include<bits/stdc++.h>

// int main(){
//     int t,n,count=0;
//     std::cin>>t>>n;


// while(t--){
//     /* code */
//     int arr[n];
//     for (int j = 0; j < n; j++)
//     {
//         /* code */std::cin>>arr[j];
//     }
//     // 0 1 2 3 4 
//     // 2 2 2 3 2 
//     for (int l = 0; l < n; l++)
//     {
//         if(arr[l]!=arr[l+1])
//         {
//             int a = arr[l];
//             int b = arr[l+1];

//         }
        

// }
// return 0;
// }

#include<bits/stdc++.h>

int main(){
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        
        int arr[n];
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        
        int uniqueIndex;
        for(int i = 0;i<n;i++){

        if (arr[i] != arr[i+1]) {
            if(i!=n-2){
            if (arr[i] == arr[i+2]) {
                uniqueIndex = i+1;
                break;
            } else {
                uniqueIndex =i;
                break;
            }
            }
            else{
                uniqueIndex = n-1;
            }
        } else {
            uniqueIndex = i;
            
        }
        }
        
        std::cout<< uniqueIndex + 1 << std::endl;  
    }
    
    return 0;
}
