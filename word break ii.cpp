#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function for backtracking
    void solve(string s, vector<string>& ans, unordered_set<string>& se, int i, int n, string tmp) {
        if (i == n) {
            ans.push_back(tmp.substr(1));  // remove leading space
            return;
        }

        for (int j = i; j < n; j++) {
            string word = s.substr(i, j - i + 1);
            if (se.count(word)) {
                solve(s, ans, se, j + 1, n, tmp + " " + word);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se(wordDict.begin(), wordDict.end());
        vector<string> ans;
        solve(s, ans, se, 0, s.size(), "");
        return ans;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    vector<string> res = sol.wordBreak(s, wordDict);

    for (const string& sentence : res) {
        cout << sentence << endl;
    }

    return 0;
}
