#include <iostream>

using namespace std;
int reducer(int x){
    long long sum = 0;
    while(x>0){
        sum += x%10;
        x = x/10;
    }
    return sum;
}
int main(){
    int t;
    cin>>t;

    while(t-->0){
        int n;
        cin>>n;

        long long sum = 0;
        int count =1;
        for(int i = 1;i<= n;i++){
            // sum +=count;
            // cout<<i<<" "<<count<<" "<<sum<<endl;
            // count++;
            // if(count  == 10){
            //     count  =1;
            // }
            sum += reducer(i);
        }
        cout<<sum<<endl;
    }
    return 0;
}