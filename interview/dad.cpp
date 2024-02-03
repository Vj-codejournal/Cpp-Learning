#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        
        long long n,m;
        cin>>n>>m;

        long long a[n];
        long long b[m];

        for(long long i = 0;i<n;i++){
            cin>>a[i];
        }
        for(long long i = 0;i<m;i++){
            cin>>b[i];
        }

        sort(a,a+n);
        sort(b,b+m);
        int D = 0;
        int i = 0,j = 0,k = n-1,l = m-1;

        while(i<k && j<l){
            D += abs(a[i]-b[l]) + abs(b[j]-a[k]);

            i++;
            j++;
            k--;
            l--;
            
        }
        if(i == k || j == l){
            D += max(abs(a[i]-b[l]),abs(b[j]-a[k]));
        }


        cout<<D<<endl;

    }    

    return 0;
}


/*
int n,f,a,b;
        cin>>n>>f>>a>>b;
        int m[n];
        for(int i = 0;i<n;i++){
            cin>>m[i];
        
        }

*/