#include <iostream>

using namespace std;

int main(){
    int a;
    cin>>a;
    int c =0;
    for(int i=1;i<20;i++){
        
        if(a != 0){
            a = a/10;
        }
        
        else{
            cout<<"The number of digit is "<<c;
            break;

        }
        c++;
    }

    return 0;
}

/*
#include <iostream>

using namespace std;

int main(){
    int count =0;
    int n;
    cin>>n;

    while(n>0){
        n= n/10;
        count++;
    }

    cout<<count;
    return 0;
}

*/