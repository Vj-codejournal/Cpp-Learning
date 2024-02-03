//https://leetcode.com/problems/word-ladder-ii/

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        int level = 0;
        vector<vector<string>>ans;

        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            if(vec.size() > level){//prev level pe jo jo use ho gaye hai unhe hata do
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);

                }
                usedOnLevel.clear();
            }
            string word = vec.back();//last word of list ke saare combos dhekne hai

            if(word == endWord){


                //the first sequence wherer we reached end
                if(ans.size() == 0){
                    ans.push_back(vec);

                }
                else if(ans.back().size() == vec.size()){
                    ans.push_back(vec);
                }//as need the minimum length sequence that we got on first time

            }
            for(int i = 0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.count(word) > 0){//to check if the word is in set
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);//track the words used on this level
                        vec.pop_back();//back track for other have to on the same level have to remove this 

                    }
                }
                word[i] = original;
            }
        }
    }
};
int main(){
    
    return 0;
}


//optimized

class Solution {
    unordered_map<string,int> map;
    vector<vector<string>> ans;
    string b;
    void dfs(string word,vector<string> &seq){
        if(word == b){
            reverse(seq.begin(),seq.end());//and endWord was first here
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());//as backtrack not disturb the sequence
            return;
        }
        int sz = word.size();
        int steps = map[word];
        for(int i = 0;i<sz;i++){
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(map.find(word) != map.end() && map[word] + 1 == steps){//abhi jis word pe hai usse ek phele wala word hona chaiye
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();
                    }
                }
                word[i] = original;
            }

    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        b = beginWord;
        q.push({beginWord});
        map[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);
        while(!q.empty()){
            string word= q.front();
            int steps = map[word];
            q.pop();
            if(word == endWord) break;
            for(int i = 0;i<sz;i++){
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.count(word)>0){
                        q.push(word);
                        st.erase(word);
                        map[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if(map.find(endWord) != map.end()){//if end word is not in map then to find it it iterated through all map and stop at end() so if find(endword) == map.end then endword is not in map
            vector<string> seq;
            seq.push_back(endWord);

            dfs(endWord,seq);
        }
        //else return empty list
        return ans;
    }
};