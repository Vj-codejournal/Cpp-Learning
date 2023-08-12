//ways to create multidimensionnal array
//double pointer
#include <iostream>

using namespace std;

int main(){
    int m =3,n=2;
    int **arr;
    arr = new int *[m];//givrn the pointer the first address of the array m // new is used to dynamically allocate memory blocks in heaps segment of memory//thid is a method to dynamically allocate m rows make them 
    for(int i = 0;i<m;i++){
        arr[i]= new int [n];//if n is replaced with i+1 then 1st array will be of size 1 then 2 then 3 not all will be of size n //stored address of each row of n to a element of m 
    }//for each row of m n coloumns are created dynamically

    for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
            arr[i][j]=10;
            cout<<arr[i][j]<<" ";
        }
    }
    return 0;
}


// array of pointers
//here just make a array of pointers directly without using double ptr

#include <iostream>

using namespace std;

int main(){
    int m =3,n=2;
    int *arr[m];//normal array of pointers allocated on stack not dynamically

    for(int i = 0;i<m;i++){
        arr[i]= new int [n];
    }

    for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
            arr[i][j]=10;
            cout<<arr[i][j]<<" ";
        }
    }
    return 0;
}


//array of vectors


#include <iostream>
#include<vector>
using namespace std;

int main(){
    int m =3,n=2;
    vector<int> arr[m];// created m vectors when m is no. of rows
    for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i].push_back(10);//for ever row we push n items in each row so like make n coloum for each row then put 10 in them as pushed10
        }
    }
    for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
            arr[i][j]=10;
            cout<<arr[i][j]<<" ";
        }
    }
    return 0;
}

//vector of vectors
#include <iostream>
#include<vector>
using namespace std;

int main(){
    int m =3,n=2;
    vector<vector<int>> arr;
    for(int i = 0;i<m;i++){
        vector<int> v; //dynamically created the rows individually one by one then filled coloums in it dynamically then pushback this row also to create the next row
        for(int j=0;j<n;j++){
            v.push_back(10);
        }
        arr.push_back(v);
    }
    for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
            arr[i][j]=10;
            cout<<arr[i][j]<<" ";
        }
    }
    return 0;
}

//vectors create at random address not continous