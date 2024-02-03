#include <iostream>

using namespace std;
void sayDigit(int n,string * spelling){
    if(n == 0){
        return;
    }

    int digit = n%10;
    n = n/10;

    sayDigit(n,spelling);

    cout<<spelling[digit]<<" ";

}
int main(){
    int n;
    string spelling[10] = {"zero" ,"one","two","three","four","five","six","seven","eight","nine"};

    cin>>n;

    sayDigit(n,spelling);
    return 0;
}