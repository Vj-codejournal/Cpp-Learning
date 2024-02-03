

#include <iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    void solve(string digits,string output,int index,vector<string> &ans,map<char,string> m){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        auto it = m.find(digits[index]);
        string value = (*it).second;
        for(int i= 0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,output,index+1,ans,m);
            output.pop_back();//remove single a from output here as from there we already got ad ae af so a remove backtracking
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }
        string output = "";
        int index = 0;
        map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        
        solve(digits,output,index,ans,m);
        return ans;
    }
};
int main(){
    string digits = "23";
    Solution s;
    vector<string> ans = s.letterCombinations(digits);

    for(auto x : ans){
        cout<<x<<" ";
    }
    
    return 0;
}

//23
/*
for 2 ek bar a b c le liye ab 3 pe gaye a ke liye ek bar d e f le liye and so on
*/

/*
output.pop_bacK reason

ip 23 op " " empty string
now for 2 for loop run a b c eack one time
for "a" call d  e f
ad ae af all pushed to ans as base case now return 
"a" this state have to remove "a" to again make empty string so for next for loop of b can again get a empty string to fill if not "a" will already be there
*/