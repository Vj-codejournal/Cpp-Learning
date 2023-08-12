//tell max element in array
//function template
#include <iostream>

using namespace std;
template<typename T,int limit>//can set limit to array that can be passed from main
T arrMax(T arr[],int n)
{//put condition if(n>limit) here to pass a certain limit of array only
    T res = arr[0];
    for(int i=0 ;i<n;i++){
        if(arr[i]>res)
        res =arr[i];
    }
    return res;
}
int main(){
    int arr1[] = {10,40,3};
    cout<<arrMax<int,4>(arr1,3);//4 is the non datatype value passed here must be a constant cant be a variable
    //so it do int x =4 and put x here not work but can do const int x =4
    float arr2[] = {10.5,3.5,1.5,30.5};
    cout<<arrMax<float,4>(arr2,4);

    return 0;
}