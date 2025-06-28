#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        int ans = 0;
        int cnt = 0;
        int oddCount = 0;

        while (r < n) {
            if (nums[r] % 2 == 1) {
                oddCount++;
                cnt = 0;
            }

            while (oddCount == k) {
                cnt++;
                if (nums[l] % 2 == 1) {
                    oddCount--;
                }
                l++;
            }

            ans += cnt;
            r++;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << sol.numberOfSubarrays(nums, k) << endl;
    return 0;
}
