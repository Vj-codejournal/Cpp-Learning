//array traversal- to pass through an array
//1. use normal loop
#include <iostream>

using namespace std;

int main(){
    
    int arr[]={10,20,30,40,50};
    cout<<sizeof(arr);
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" "; 
    }

    //to mordify in this
    for(int i =0;i<n;i++){
        arr[i] = arr[i]*2;
    }
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
    return 0;
}

//2. Range based for loop
#include <iostream>

using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    for(int x:arr)//every variable of array will be assigned to x one by one so it traverse through them
    {
        cout<<x<<" ";
    }
    //here no need to figure out the size of array and many more things optimized
    return 0;
}

//mordify array element during traversal

#include <iostream>

using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    for(int &x:arr){//access the address of array to change its value by call by reference
        x =x*2;
    }
    for(int x:arr)
        cout<<x<<" ";
    
    return 0;
}