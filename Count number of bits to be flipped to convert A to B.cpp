#include <iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = start ^ goal;
        int ans = 0;
        while (cnt > 0) {
            ans += cnt & 1;
            cnt >>= 1;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int start = 10; // binary: 1010
    int goal = 7;   // binary: 0111
    cout << "Minimum bit flips needed: " << sol.minBitFlips(start, goal) << endl;
    return 0;
}
