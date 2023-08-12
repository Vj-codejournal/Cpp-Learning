#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[] = {10,15,8,20};
    sort(arr,arr+4);//sort algo directly sort the array give address of start and one after the end

    for(int i = 0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    if (binary_search(arr,arr+4,8))//returns a boolean value true 1 if 8 is present
        cout<<"present";
    else
        cout<<"Not present";
    return 0;
}