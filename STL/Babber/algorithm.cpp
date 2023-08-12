#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);//must be sorted for binary search

    cout<<"Finding 6 --> "<<binary_search(v.begin(),v.end(),6)<<endl;
    cout<<"Lower bound --> "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;// if there are 2 6 in a array the one which comes first is lower bound // minimum indx where 6 appear
    cout<<"Upper bound --> "<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;

    int a =3;
    int b=6;
    cout<<"max ->"<<max(a,b);
    cout<<"min ->"<<min(a,b);

    swap(a,b);

    string s = "abcd";
    reverse(s.begin(),s.end());

    //can rotate the elements //1 3 6 7
    rotate(v.begin(),v.begin()+1,v.end());
    //3 6 7 1

    return 0;
}