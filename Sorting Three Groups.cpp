#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(4, n);
        for (auto it : nums) {
            dp[it]--;
            dp[2] = min(dp[1], dp[2]);
            dp[3] = min(dp[2], dp[3]);
        }
        return dp[3];
    }
};

int main() {
    vector<int> nums = {2, 1, 3, 1, 2, 1};
    Solution sol;
    cout << sol.minimumOperations(nums) << endl;
    return 0;
}
