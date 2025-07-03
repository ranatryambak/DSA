#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> v(n, 0);

        for (int i = 1; i < n; i++) {
            int x = v[i - 1];
            while (x > 0 && s[i] != s[x]) {
                x = v[x - 1];
            }
            if (s[i] == s[x]) x++;
            v[i] = x;
        }

        return s.substr(0, v.back());
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    string result = sol.longestPrefix(input);
    cout << "Longest prefix which is also suffix: " << result << endl;

    return 0;
}
