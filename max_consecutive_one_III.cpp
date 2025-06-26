#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;              // Count of zeros flipped so far
        int left = 0, right = 0;  // Sliding window
        int ans = 0;

        while (right < n) {
            if (nums[right] == 0) {
                if (cnt < k) {
                    cnt++; // Flip a 0 to 1
                } else {
                    // Move the left pointer until one 0 is removed
                    while (left <= right && nums[left] == 1) {
                        left++;
                    }
                    left++; // skip the 0
                }
            }
            right++;
            ans = max(ans, right - left);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements (0 or 1): ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "Enter max number of 0s you can flip (k): ";
    cin >> k;

    int result = sol.longestOnes(nums, k);
    cout << "Longest sequence of 1s after flipping at most " << k << " zeros: " << result << endl;

    return 0;
}
