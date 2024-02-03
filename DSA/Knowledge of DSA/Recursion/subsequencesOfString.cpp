
//https://www.codingninjas.com/studio/problems/subsequences-of-string_985087?leftPanelTab=0
#include <bits/stdc++.h> 
using namespace std;
void solver(string str,vector<string> &ans, string output,int index){
    if(index >= str.size()){
        if(output.length() >0)//empty string not needed
        ans.push_back(output);
        return;
    }

    solver(str,ans, output,index+1);

    char element = str[index];
    output += element;
    solver(str,ans, output,index+1);
    
}
vector<string> subsequences(string str){
	
	vector<string> ans;
    string output = "";
    int index = 0;

    solver(str,ans,output,index);
	return ans;
}
