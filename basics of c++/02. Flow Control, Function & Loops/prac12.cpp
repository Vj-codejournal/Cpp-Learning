#include <iostream>

using namespace std;

int main(){
    int a,b;
cin >>a>>b;

int x = min(a,b); 
int y = max(a,b);


for(int i = 1;i<100;i++){
    int var = x*i;
    if(var% y == 0){
        cout<<"LCM is "<<var;
        break;
    }
}

    return 0;
}

/*
for 6 and 12 lcm can skip to check 6 as that cant be lam thats why we take max first 

int a,b;
cin>>a>>b;
int start = max(a,b);
int end = a*b;
int ans = start;

for(int i =start; i<=end;i++){
    if(i%a and i%b ==0){
        ans = i;
        break;
    }
}
cout<<ans;
*/