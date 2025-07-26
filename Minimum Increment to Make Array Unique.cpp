#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] >= nums[i + 1]) {
                ans += nums[i] - nums[i + 1] + 1;
                nums[i + 1] = nums[i] + 1;
            }
        }
        return ans;
    }
};

int main() {
    // Sample input
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    
    // Create an object of the Solution class
    Solution sol;
    
    // Call the function and print the result
    int result = sol.minIncrementForUnique(nums);
    cout << "Minimum increments needed to make all elements unique: " << result << endl;

    return 0;
}
