#include <iostream>

using namespace std;
bool Search(int *arr,int size,int key){
    if(size == 0){ 
        return false;
    }

    if(arr[0] == key){
        return true;
    }
    else{
        bool remainingPart = Search(arr+1,size-1,key);
        return remainingPart;
    }

}
int main(){
    int arr[5] = {3,5,1,2,6};
    int size = 5;
    int key = 2;
    bool ans = Search(arr,size,key);

    if(ans){
        cout<<"key found";
    }
    return 0;
}