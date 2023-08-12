//not understood
#include <iostream>

using namespace std;
class ArraySizeZeroException{ };
class ArraySizeNegativeException{ };

int average(int arr[],int n){
    if(n==0)throw ArraySizeZeroException();
    if(n<0)throw ArraySizeNegativeException();
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum +=arr[i];
        return sum/n;
    }
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    try{
        int res = average(arr,n);
        cout<<res;
    }
    catch(ArraySizeZeroException &e1){//object of this class is made in catch
        cout<<"Array size is zero";
    }
    catch(ArraySizeNegativeException &e2){//object of this class is made in catch
        cout<<"Array size is Negative";
    }
    
    return 0;
}



#include <iostream>
#include <exception>

using namespace std;
class MyException : public exception//in herit from inbuilt excetion class
{
    virtual const char *what() const throw(){//throw's () is empty  as to be not caught here inside class only
        return "Exception Occured\n";
    }
};
int main(){
    try{
        throw MyException();
    }
    catch(exception &e1){//can write myexception here also nut point is all user class inherit from exception class can always use execption object to catch when MyException has virtual function also over written original what function of exception class so get now our defined what function
        cout<<e1.what();//even if exception catch it and not myexception still what will return result of myexception only and not what defined in exception class this happened due to virtual function //as what of base class is used as virtual in derived so now for what function derived class is called
    }
    return 0;
}