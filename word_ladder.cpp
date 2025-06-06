#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        vector<string> v;
        q.push({beginWord,1});
        int ans = 0;
        while(!q.empty()){
            string tmp = q.front().first;
            int step = q.front().second;
            q.pop();
            string word = tmp;
            if(tmp == endWord){
                ans = step;
                break;
            }
            for(int i=0;i<tmp.size();i++){
                for(int j='a';j<='z';j++){
                    tmp[i] = j;
                    if(s.find(tmp)!=s.end()){
                        q.push({tmp,step+1});
                        s.erase(tmp);
                    }
                }
                tmp = word;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << result << endl;
    return 0;
}
