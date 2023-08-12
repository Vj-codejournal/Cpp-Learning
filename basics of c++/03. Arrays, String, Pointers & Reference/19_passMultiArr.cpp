//passing multidimensional array to function
#include <iostream>

using namespace std;
void print(int mat[3][2]){//problem of this is print function only works for a 3x2 matrix only
//to solve this can pass number of rows as extra argument int m but can do this for coloum as only row even if ommited still work do (int mat[][2],int m) //cant ommit both so use global variable but still 3x2 bound
    for(int i=0;i<3;i++){
        for(int j =0;j<3;j++){
            
            cout<<mat[i][j]<<" ";
        }
}
} 
int main(){
    int mat[3][2] = {{10,20},{30,40},{50,60}};

    print(mat);
    return 0;
}


//write a function to work for any dimension of matrix

//double pointer
#include <iostream>

using namespace std;
void print(int **arr,int m,int n){//double pointer to specify the 2d array
    for(int i=0;i<3;i++){
        for(int j =0;j<2;j++){
            cout<<arr[i][j]<<" ";
        }
}
} 
int main(){
    int **arr;
    int m=3,n=2;
    arr = new int *[m];
    for(int i =0 ;i<m;i++)
    {
        arr[i] = new int [n];
        for(int j=0;j<n;j++){
            arr[i][j] = i;
            //cout<<arr[i][j]<<" ";
        }
    }    
    print(arr,m,n);
    
    return 0;
}


//array of pointers
#include <iostream>

using namespace std;
void print(int *arr[],int m,int n){
    for(int i=0;i<3;i++){
        for(int j =0;j<2;j++){
            cout<<arr[i][j]<<" ";
        }
}
} 
int main(){
    int m=3,n=2;
    int *arr[m];
    
    for(int i =0 ;i<m;i++)
    {
        arr[i] = new int [n];//new used to dynamically allocate new row int [3] make 3 row here
        for(int j=0;j<n;j++){
            arr[i][j] = i;
            //cout<<arr[i][j]<<" ";
        }
    }    
    print(arr,m,n);
    
    return 0;
}

//array of vectors
#include <iostream>
#include<vector>
using namespace std;
void print(vector<int> arr[],int m){
    for(int i=0;i<3;i++){
        for(int j =0;j<arr[i].size();j++){//can get no of coloum by this it is size of each row that is no of vectors created 
            cout<<arr[i][j]<<" ";
        }
}
} 
int main(){
    int m=3,n=2;
    vector<int> arr[m];
    
    for(int i =0 ;i<m;i++)
    {
        for(int j=0;j<n;j++){
            arr[i].push_back(i);
            //cout<<arr[i][j]<<" ";
        }
    }    
    print(arr,m);
    
    return 0;
}

//vectors of vectors

#include <iostream>
#include<vector>
using namespace std;
void print(vector<vector<int>> &arr){//passed by refrence
    for(int i=0;i<arr.size();i++){
        for(int j =0;j<arr[i].size();j++){ 
            cout<<arr[i][j]<<" ";
        }
}
} 
int main(){
    int m=3,n=2;
    vector<vector<int>> arr;//no need to put row here also
    
    for(int i =0 ;i<m;i++)
    {   vector<int> v;
        for(int j=0;j<n;j++){
            v.push_back(i);//create coloum for one row
            
        }
        arr.push_back(v);//create next row
    }    
    print(arr);
    
    return 0;
}
