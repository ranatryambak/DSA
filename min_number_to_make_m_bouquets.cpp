#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool valid(vector<int> v, int m, int k, int mid) {
        int a = 0;
        int b = 0;
        for (auto it : v) {
            if (it <= mid) {
                a++;
            } else {
                a = 0;
            }
            if (a == k) {
                b++;
                a = 0;
            }
        }
        if (b >= m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = INT_MAX, high = INT_MIN;
        for (auto it : bloomDay) {
            low = min(low, it);
            high = max(high, it);
        }
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (valid(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2}; // sample input
    int m = 3; // number of bouquets
    int k = 1; // number of flowers per bouquet

    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum number of days: " << result << endl;

    return 0;
}
