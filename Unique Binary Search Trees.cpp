#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= i; j++) {
                cnt += dp[j - 1] * dp[i - j];
            }
            dp[i] = cnt;
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << "Number of unique BSTs with " << n << " nodes: " << sol.numTrees(n) << endl;
    return 0;
}
