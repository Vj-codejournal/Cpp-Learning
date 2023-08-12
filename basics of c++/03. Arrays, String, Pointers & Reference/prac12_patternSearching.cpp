#include <iostream>

using namespace std;
void printIndex(string text,string pat){
    int found = text.find(pat);//give index where we first get the pattern
    while(found != string::npos){//till the string end
    cout<<"Pattern found at "<< found <<endl;

    found = text.find(pat,found+1);//if found first pattern at index 0  now it start to search from index 1

    }
}
int main(){
    string text,pat;
    cin>>text>>pat;

    printIndex(text,pat);
    return 0;
}