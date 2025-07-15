class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> v(n, vector<int>(m, 0));
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        int ans = 0;

        // Build indegree for each cell
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[x][y] < matrix[nx][ny]) {
                        v[nx][ny]++;
                    }
                }
            }
        }

        // Start from cells with 0 indegree
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // BFS Topological Sort
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[x][y] < matrix[nx][ny]) {
                        v[nx][ny]--;
                        if (v[nx][ny] == 0) {
                            q.push({nx, ny});
                        }
                    }
                }
            }
            ans++;
        }

        return ans;
    }
};
