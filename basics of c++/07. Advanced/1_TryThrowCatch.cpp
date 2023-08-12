#include <iostream>

using namespace std;

int main(){
    int x,y;
    cin>>x>>y;

    try{
        if(y==0)
            throw 0;

        cout<<"Result is "<<x/y;//if y =0 not come on this statement, avoid crashing
    }
    catch(int x){//data type written here should match the thrown variable
        cout<<"Diviser is zero";
    }
    return 0;
}


#include <iostream>

using namespace std;

int main(){
    double x,y;
    cin>>x>>y;

    try{
        if(x==0)
            throw 0;//this is int data type
        
        if(y==0)
            throw string("Y is Zero");

        if(x+y < 0.0)
            throw (x+y);
    }
    catch(int e1){cout<<e1;}
    catch(string &e2){cout<<e2;}
    catch(...){cout<<"x+y is less than 0";}// ... means catch all if a data type isnt present in other catch condition it will catch them, like here double is thrown x+y but no one to catch it so this will catch it
    cout<<"\n bye";
    return 0;
}
//if first if condition is satisfied it will throw and no further if conditions checked as after throw get out of try and go to see check
//if for a thrower data type there is no catch block it crash that why use ...

#include <iostream>
int average(int arr[],int n)throw(string){//mentioned here before hand the possible thrown exception not nessesary to do but recommended
    if(n==0)
    throw string("Array size is zero");

    int sum = 0;
    for(int i = 0;i<n;i++){
        sum = sum +arr[i];

        return sum/n;
    }
}
using namespace std;

int main(){
    int arr[] = {4,5,2};

    int n =0 ;

    try{
        int res = average(arr,n);
        cout<<res;
    }
    catch(string &e){cout<<e;}
    cout<<"Bye";
    return 0;
}