#include <iostream>

using namespace std;
void TOH(int n,char A,char B,char C){
    if(n>0){
        TOH(n-1,'A','B','C');
        cout<<"Move a Disc from "<<A<<" to "<<C<<endl;
        TOH(n-1,'B','A','C');
    }
}
int main(){
    int n;
    cin>>n;

    TOH(n,'A','B','C');
    return 0;
}