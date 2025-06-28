#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;
        int res = 0;

        for (int i = 0; i < k; i++) {
            ans += cardPoints[i];
        }

        res = ans;

        for (int i = 0; i < k; i++) {
            ans -= cardPoints[k - i - 1];
            ans += cardPoints[n - i - 1];
            res = max(ans, res);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << sol.maxScore(cardPoints, k) << endl; // Output should be 12
    return 0;
}
