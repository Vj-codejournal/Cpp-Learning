//loops same as c

#include <iostream>

using namespace std;

int main(){
    for(int i =0;i<3;i++){//initialize once at start
        cout<<"HI"<<"\n";

    }
    //cout<<i; give error as i accessable inside loop only if declare i outside of loop at top then accessable here also
    return 0;
}