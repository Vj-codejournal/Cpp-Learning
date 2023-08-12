#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Enter the two numbers\n";
    cin >> a >> b;

    if (a > b)
    {
        for (int i = b; i > 0; i--)
        {
            if (a % i == 0)
            {
                cout << i << "is the GCD";
                break;
            }
        }
    }
    else
    {
        for (int i = a; i > 0; i--)
        {
            if (b % i == 0)
            {
                cout << i << " is the GCD";
                break;
            }
        }
    }
    return 0;
}


/*
int a,b;
cin>>a>>b;

int x = min(a,b); // have to use cmath or just make a function and find

int ans =1;

for(int i =1;i <=x;i++){
    if(a%i == 0 and b%i ==0){
        ans =i;
    }
}
cout<<ans;
*/