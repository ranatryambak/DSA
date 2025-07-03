#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string a = s;
        reverse(a.begin(), a.end());
        string tmp = s + "#" + a;
        int n = tmp.size();
        vector<int> v(n, 0);
        for (int i = 1; i < n; i++) {
            int len = v[i - 1];
            while (len > 0 && tmp[i] != tmp[len]) {
                len = v[len - 1];
            }
            if (tmp[i] == tmp[len]) len++;
            v[i] = len;
        }
        string ans = s.substr(v.back());
        reverse(ans.begin(), ans.end());
        ans += s;
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "aabba";
    cout << sol.shortestPalindrome(s) << endl;
    return 0;
}
