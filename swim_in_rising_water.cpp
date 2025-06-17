#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> q;

        vector<vector<int>> v(n, vector<int>(n, 0));
        v[0][0] = 1;
        q.push({grid[0][0], {0, 0}});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};

        while (!q.empty()) {
            int ans = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();

            if (r == n - 1 && c == n - 1) return ans;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !v[nr][nc]) {
                    v[nr][nc] = 1;
                    q.push({max(ans, grid[nr][nc]), {nr, nc}});
                }
            }
        }

        return -1; // This line will never be reached due to problem constraints
    }
};

// Example usage (for local testing)
int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 2}, {1, 3}};
    cout << sol.swimInWater(grid) << endl;  // Output: 3
    return 0;
}
