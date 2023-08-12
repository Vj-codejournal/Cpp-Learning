#include <iostream>
#include<vector>
using namespace std;

int rowZero(vector<vector<int>> &arr,int i,int j);
int coloumZero(vector<vector<int>> &arr,int i,int j);
int main(){
    int m,n,c=-1,e=-1,f=-1,d=-1,a;
    cout<<"Enter the dimensions of matrix(mxn):";
    cin>>m>>n;
    cout<<"Enter the elements row by row\n";
    vector<vector<int>> arr;
    for(int i =0 ;i<m;i++)
    {   vector<int> v;
        for(int j=0;j<n;j++){
            cin>>a;
            v.push_back(a);
            
        }
        arr.push_back(v);
    }
    
    for(int  i=0;i<m;i++){
        for(int j=0;j<n;j++){
        if(j != c&&j != e&&i != f&&i != d){
            if(arr[i][j]==0){
                e =rowZero(arr,i,j);
                f =coloumZero(arr,i,j);//stackoverflow chances
                
                c = j;
                d=i;
                
                
            }
        }

        
        }
    }

    for(int  i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}

int rowZero(vector<vector<int>> &arr,int i,int j){
    int c = -1;
    for(int k=0;k<arr[i].size();k++){
            if(arr[i][k] == 0 && k != j){
                coloumZero(arr,i,k);
                c = k;
            }
            else{ 
                arr[i][k] =0;
                }
            }
            if(c != -1 )
            return c;
            else 
            return j;
            
}
int coloumZero(vector<vector<int>> &arr,int i,int j){
    int c = -1;
    for(int k=0;k<arr.size();k++){
            if(arr[k][j] == 0 && k != i ){
                rowZero(arr,k,j);
                c = k;
            }
            else{
                arr[k][j] =0;
                }
            }
            if(c != -1 )
            return c;
            else 
            return i;
}

