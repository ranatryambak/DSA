#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumCost(string s) {
        long long ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                ans += min(i, n - i);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example test case
    string s;
    cout << "Enter the binary string: ";
    cin >> s;

    long long cost = sol.minimumCost(s);
    cout << "Minimum cost: " << cost << endl;

    return 0;
}
