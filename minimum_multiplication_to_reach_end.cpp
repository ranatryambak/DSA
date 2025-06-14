#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> v(100000, INT_MAX);
        int mod = 100000;
        v[start] = 0;
        queue<pair<int, int>> q;
        q.push({0, start});
        while (!q.empty()) {
            int x = q.front().first;
            int node = q.front().second;
            q.pop();
            if (node == end) return v[end];
            for (auto it : arr) {
                int y = it * node % mod;
                if (x + 1 < v[y]) {
                    v[y] = x + 1;
                    q.push({x + 1, y});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> arr = {2, 5, 7};
    int start = 3, end = 30;
    cout << s.minimumMultiplications(arr, start, end) << endl;
    return 0;
}
