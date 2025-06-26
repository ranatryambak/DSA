#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        int j = 0;
        vector<int> v(256, 0);  // ASCII character frequency map

        for (int i = 0; i < n; i++) {
            if (v[s[i]] != 0) {
                maxlen = max(maxlen, i - j);
                while (j <= i) {
                    if (s[i] == s[j]) break;
                    v[s[j]]--;
                    j++;
                }
                j++;
            } else {
                v[s[i]]++;
            }
        }

        maxlen = max(maxlen, n - j);
        return maxlen;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
