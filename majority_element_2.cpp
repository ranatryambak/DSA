#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        int cnt = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                cnt++;
            } else {
                if (cnt > n / 3)
                    ans.push_back(nums[i - 1]);
                cnt = 1;
            }
        }

        if (cnt > n / 3)
            ans.push_back(nums[n - 1]);

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3, 2, 2, 1, 1};
    vector<int> result = sol.majorityElement(nums);

    cout << "Majority elements (appearing more than n/3 times): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
