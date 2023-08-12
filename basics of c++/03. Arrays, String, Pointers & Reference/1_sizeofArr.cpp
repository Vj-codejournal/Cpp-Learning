//size of array

#include <iostream>

using namespace std;

int main(){
    
    int arr[]={10,20,30,40,50};
    cout<<sizeof(arr);//give total size of arr 5 int each of 4 byte

    //count the number of element in aan array
    //total size of arr div by 4 as each element of 4 byte
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n;
    return 0;
}