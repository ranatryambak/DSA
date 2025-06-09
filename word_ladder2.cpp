#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<string>> ans;
    map<string,int> mp;
    string a;
private:
    void dfs(string b,vector<string> &v){
        if(b==a){
            reverse(v.begin(),v.end());
            ans.push_back(v);
            reverse(v.begin(),v.end());
            return;
        }

        int step = mp[b];
        for(int i=0;i<b.size();i++){
            char word = b[i];
            for(char j='a';j<='z';j++){
                b[i] = j;
                if(mp.find(b)!=mp.end()&&mp[b]+1==step){
                    v.push_back(b);
                    dfs(b,v);
                    v.pop_back();
                } 
            }
            b[i] = word;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        a = beginWord;
        s.erase(beginWord);
        mp[beginWord] = 0;
        q.push(beginWord);
        
        while(!q.empty()){
            string tmp = q.front();
            int step = mp[tmp];
            q.pop();
            string word = tmp;
            if(tmp == endWord){
                break;
            }
            for(int i=0;i<tmp.size();i++){
                for(int j='a';j<='z';j++){
                    tmp[i] = j;
                    if(s.find(tmp)!=s.end()){
                        q.push(tmp);
                        mp[tmp] = step+1;
                        s.erase(tmp);
                    }
                }
                tmp = word;
            }
        }
        if(mp.find(endWord)!=mp.end()){
            vector<string>v;
            v.push_back(endWord);
            dfs(endWord ,v );
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);
    for (auto& path : result) {
        for (auto& word : path) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
