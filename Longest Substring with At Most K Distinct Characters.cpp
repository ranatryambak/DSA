#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        int l = 0, r = 0;
        int ans = -1;
        while (r < n) {
            mp[s[r]]++;
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            if (mp.size() == k)
                ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

int main() {
    string s = "aabacbebebe";
    int k = 3;
    Solution obj;
    cout << obj.longestKSubstr(s, k) << endl;
    return 0;
}
