#include <iostream>
using namespace std;
int main(){
    int x;
    double d;
    cout<<sizeof(x)<<"\n";
    cout<<sizeof(d)<<"\n";
    cout<<sizeof(10ll)<<"\n";  // after 10 put ll make it long long just can put suffix to define data type
    cout<<sizeof(10.5); //by default double to make float have to do 10.5f
    return 0;
}