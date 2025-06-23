#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;

    void solve(string s, int n, vector<string> v, int i) {
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
            while (k <= j) {
                if (tmp[k] != tmp[j]) {
                    flag = false;
                    break;
                }
                k++;
                j--;
            }
            if (flag) {
                v.push_back(tmp);
                solve(s, n, v, a + 1);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        solve(s, n, {}, 0);
        return ans;
    }
};

int main() {
    Solution sol;
    string input = "aab";

    vector<vector<string>> result = sol.partition(input);

    cout << "Palindrome partitions:\n";
    for (const auto& partition : result) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
