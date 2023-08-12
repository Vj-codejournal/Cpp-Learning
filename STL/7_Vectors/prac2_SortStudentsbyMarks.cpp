#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int myCmp(pair<int,int> p1 , pair<int,int>p2){
    return p1.second > p2.second;//give priority to the elemnt whose second is higher so now decreasing order according to 2nd term
}
void printSortedByMarks(int roll[],int marks[],int n){
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({roll[i],marks[i]});
    }
    sort(v.begin(),v.end(),myCmp);
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second;
        cout<<endl; 
    }

}
int main(){
    //default sort compare according to first value of pair so make your own function to compare 2nd terms//also sort go in increasing order also correct that or just traverse vector in reverse while printing
    int roll[]={101,103,105};
    int marks[]={80,70,90};
    printSortedByMarks(roll,marks,3);
    return 0;
}


//method 2 put marks first in pair to sort according to it

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void printSortedByMarks(int roll[],int marks[],int n){
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({marks[i],roll[i]});
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());//now sort greater to smaller, pass greater<datatype>
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second;
        cout<<endl; 
    }

}
int main(){
    int roll[]={101,103,105};
    int marks[]={80,70,90};
    printSortedByMarks(roll,marks,3);
    return 0;
}

//to optimise more
//can do make a vector function and pass as a pair

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

void printSortedByMarks(vector<pair<int,int>> v,int n){
    
    sort(v.begin(),v.end(),greater<pair<int,int>>());//now sort greater to smaller, pass greater<datatype>
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second;
        cout<<endl; 
    }

}
int main(){
    int roll[]={101,103,105};
    int marks[]={80,70,90};
    int n =3;
    vector<pair<int,int>> p1;
    for(int i=0;i<n;i++){
        p1.push_back({marks[i],roll[i]});
    }
    printSortedByMarks(p1,n);
    return 0;
}