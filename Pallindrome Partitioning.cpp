#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;

    // Helper function to perform backtracking
    void solve(string s, int n, vector<string> &v, int i) {
        if (i >= n) {
            ans.push_back(v);
            return;
        }

        string tmp = "";
        for (int a = i; a < n; a++) {
            tmp += s[a];
            int j = tmp.size() - 1;
            int k = 0;
            bool flag = true;

            // Check if the current substring tmp is a palindrome
            while (k <= j) {
                if (tmp[k] != tmp[j]) {
                    flag = false;
                    break;
                }
                k++;
                j--;
            }

            // If it is a palindrome, recurse further
            if (flag) {
                v.push_back(tmp);
                solve(s, n, v, a + 1);
                v.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> v;
        solve(s, n, v, 0);
        return ans;
    }
};

// Driver code (for testing purposes)
int main() {
    Solution sol;
    string s = "aab";
    vector<vector<string>> res = sol.partition(s);

    for (auto vec : res) {
        for (auto str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
