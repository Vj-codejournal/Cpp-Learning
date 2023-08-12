#include <bits/stdc++.h>

 
using namespace std;
void merge(int *arr,int s,int e){
    int mid =(s+e)/2;
    //split to 2 array
    int len1 = mid - s+1;
    int len2 = e-mid;
    int *first = new int(len1);
    int *second = new int(len2);
    //copy values in spilited two arrays
    int k =s;
    for(int i = 0;i<len1;i++){
        first[i] = arr[k++];
    }
    k = mid+1;
    for(int i = 0;i<len2;i++){
        second[i] = arr[k++];
    }

    //now merging happen
    int index1=0;//of 1st array
    int index2=0;//of 2nd array
    k = s;//k is main array index
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++] =  first[index1++];//as second not selected here its index not increasse
        }
        else{
            arr[k++] =  second[index2++];
        }
    }
    while(index1<len1){//for any left element
        arr[k++] =  first[index1++];
    }
    while(index2<len2){//for any left element
        arr[k++] =  second[index2++];
    }

    delete [] first;
    delete [] second;//as dynamically allocated so have to remove manually
}
void MergeSort(int *arr,int s,int e){
    //as it split using recurssionso when complete transversed it return
    if(s>=e){//to end the recurssion as keep split so when start beacome equal to end stop  
        return;
    }

    int mid = (s+e)/2;
    //left part sort recurssion will sort it just break
    MergeSort(arr,s,mid);

    //right part sort
    MergeSort(arr,mid+1,e);

    merge(arr,s,e);

}
int main(){
    int n;
    cin>>n;//use array in input
    int arr[n];

    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    MergeSort(arr,0 ,n-1);//start and end also send
    //vector<int> final = SelectionSort(arr,n);
    for(auto it : arr)
        cout<<it<<" ";

        
    return 0;
}