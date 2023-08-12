#include <iostream>

using namespace std;

int main(){
    int arr [3][2] = {{10,20},
                      {30,40},
                      {50,60}};//it is a 3x2 3 row 2 coloum 2D array
    
    //to traverse for 2D 2 nested loop,3D 3 nested loop
    for(int i =0;i<3;i++){//have to pass two index to access element
        for(int j =0;j<2;j++){
            cout<<arr[i][j]<<" ";
        }

    }
    return 0;
}   