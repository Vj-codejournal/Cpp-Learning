#include <iostream>

using namespace std;
struct s1{
    double d1;
    char c1;
    
    char c2;
    
};
struct s2{
    
    double d1;
    char c1;
    char c2;
    
}__attribute__((packed));

int main(){
    cout<<sizeof(s1)<<endl;
    cout<<sizeof(s2);
    return 0;
}