#include <iostream>

using namespace std;
int binarySearch(int arr[],int size,int key){
    int start = 0;
    int end = size -1;
    int mid =start + (end-start)/2;
    while(start <= end){//see the if not find till the end then to stop it
        if(arr[mid] == key){
            return mid;
        }

        //go to right part
        if(key > arr[mid]){
            start = mid +1;
        }
        else{
            end = mid -1;
        }

        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    int even[6] = {2,4,6,8,12,18};
    int odd[5] = {3,8,11,14,16};
    int evenindex = binarySearch(even,6,12);
    int oddindex = binarySearch(odd,5,8);

    cout<<"Index of 12 is"<<evenindex<<endl;
    cout<<"Index of 8 is"<<oddindex<<endl;
    return 0;
}

//Recurssion