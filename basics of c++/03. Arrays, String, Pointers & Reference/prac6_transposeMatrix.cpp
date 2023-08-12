#include <iostream>

using namespace std;

int main(){
    int m,n;
    cout<<"Enter the dimensions of matrix(mxn):";
    cin>>m>>n;
    cout<<"Enter the elements row by row\n";
    int arr[m][n];
    int transArr[n][m];
    for(int  i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }//in this consider matrix in 2d arrays row by row form (all elements in a single line) then point ptr at start of array and make it jump according to row so it goes to next rows first element and store in new array such a way to conduct a transpose now it come in 1st row 2nd coloum of new array and by loop as all rows 1st element collected bring array again at start then push ptr to next position and start the same loop
    for(int i=0;i<n;i++){
        int *ptr = &arr[0][0];
        ptr = ptr + i;
        for(int j=0;j<m;j++){
            transArr[i][j] = *(ptr);
            ptr = ptr + n;

        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<transArr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


//or take 0,1 element and put in 1,0 of a new matrix
#include <iostream>

using namespace std;

int main(){
    int m,n;
    cout<<"Enter the dimensions of matrix(mxn):";
    cin>>m>>n;
    cout<<"Enter the elements row by row\n";
    int arr[m][n];
    int transArr[n][m];
    for(int  i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int  i=0;i<m;i++){
        for(int j=0;j<n;j++){
            transArr[j][i] = arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<transArr[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

//vaector method in video see later

//same as the above method just used 2d vector

#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(n,0));// first made n rows then coloum of size n with default value as 0
    vector<vector<int>> ans(n,vector<int>(n,0));

    //now same as array take input and do further
    return 0;
}