#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Sentinel value

        int ans = 0;
        int n = s.size();
        if (n == 0) return 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter a parentheses string: ";
    cin >> s;

    int result = sol.longestValidParentheses(s);
    cout << "Longest valid parentheses length: " << result << endl;

    return 0;
}
