//https://leetcode.com/problems/word-ladder/description/



#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st (wordList.begin(),wordList.end());

        st.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i = 0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a';ch <= 'z';ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,steps+1});

                    }
                }
                word[i] = original;

            }
        }
        return 0; //if queue empty and still not found word
    }
};
int main(){
    
    return 0;
}
 

/*
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

in hit take h can change it to any letter from a - z then take i can change it to any letter from a - z if change with o get hot
now see for t any combo not in list
so now start again from 1st letter of hot 

use set as a new word insert and size not increase then word already in set

also after found a word remove it from set as if it is found anywhere after it not matter as path will be longer as still have to take the same amount of steps to reach to cog from that word
use BFS 

TC - N * wordlength * 26 *logn 
N is for queue if all elements of set are inserted to queue and log n for set
*/

