#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0;
        int ans = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        while (r < n) {
            mp[s[r]]++;
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                mp[s[l]]--;
                l++;
                ans += n - r;
            }
            r++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "abcabc";
    cout << sol.numberOfSubstrings(s) << endl;
    return 0;
}
