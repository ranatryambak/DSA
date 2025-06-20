#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int s = n + m;
        int left = (n + m + 1) / 2;
        if (n > m) return findMedianSortedArrays(nums2, nums1);

        double low = 0, high = n;
        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            double l1 = INT_MIN, l2 = INT_MIN;
            double r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n) r1 = nums1[mid1];
            if (mid2 < m) r2 = nums2[mid2];

            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if (s % 2 == 1) {
                    return max(l1, l2);
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median is: " << median << endl;

    return 0;
}
