#include <iostream>

using namespace std;

int main(){
    int m ,n ,q;
    cout<<"Enter the dimensions of matrix(mxn):";
    cin>>m>>n;
    cout<<"Enter the elements row by row\n";
    int arr1[m][n];
    for(int  i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }
    cout<<"Enter the dimensions of matrix(nxq):";
    cin>>q;
    cout<<"Enter the elements row by row\n";
    int arr2[n][q];
    for(int  i=0;i<n;i++){
        for(int j=0;j<q;j++){
            cin>>arr2[i][j];
        }
    }
    
    int res[m][q];

    for(int i =0;i<m;i++){
        for(int j=0;j<q;j++){
            res[i][j] = 0;
            
            for(int k = 0;k<n;k++){
                res[i][j] = res[i][j] + (arr1[i][k] *arr2[k][j]);
                
            }
            
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}