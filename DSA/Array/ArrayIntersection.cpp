//https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149
#include <bits/stdc++.h> 

using namespace std;
//Approach 3 - optimal Two pointer approach
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{   int i=0,j=0;
    vector<int> ans;
     while(i<n&&j<m){
         if(arr1[i]<arr2[j]){
             i++;
         }
         else if(arr1[i]>arr2[j]){
            j++;
         }
         else if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
         }
     }
     return ans;
}
int main(){
    
    return 0;
}
 
//TLE
#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr1[n];
    int arr2[m];

    for(int i = 0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i = 0;i<m;i++){
        cin>>arr2[i];
    }

    int count =0;
    int max1 = max(n,m);
    int intersection[max1];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr1[i] == arr2[j] && arr2[j] != -1){
                intersection[count] = arr2[j];
                arr2[j] = -1;

                count++;
                break;
            }
        }
    }
    cout<<"Intersection\n";
    for(int i=0;i<count;i++){
        cout<<intersection[i]<<" ";
    }

    cout<<"\nUnion\n";
    for(int i = 0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    for(int i = 0;i<m;i++){
        if(arr2[i] != -1)
        cout<<arr2[i]<<" ";
    }


    return 0;
}


//Approach 2
//arr1 1st element compare to all elements of arr2 if arr2's element is bigger then arr1's element then no need to compare to further elements of arr2 as non decreasing so will be bigger only --- also got TLE


