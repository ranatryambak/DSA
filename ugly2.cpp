#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n);  
        int x = 0, y = 0, z = 0;   
        dp[0] = 1;  

        for (int i = 1; i < n; i++) {
            long long a = dp[x] * 2;
            long long b = dp[y] * 3;
            long long c = dp[z] * 5;

            dp[i] = min({a, b, c});

            if (dp[i] == a) x++;
            if (dp[i] == b) y++;
            if (dp[i] == c) z++;
        }

        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The " << n << "-th ugly number is: " << sol.nthUglyNumber(n) << endl;
    return 0;
}
