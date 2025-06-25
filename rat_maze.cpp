#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>> maze, set<string> &ans, string tmp, int n, int i, int j) {
        if (i == n - 1 && j == n - 1) {
            ans.insert(tmp);
            return;
        }

        if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0) return;

        maze[i][j] = 0;

        string dir = "DLRU";
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            solve(maze, ans, tmp + dir[k], n, ni, nj);
        }

        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        set<string> ans;
        string v = "";
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) return {};
        solve(maze, ans, v, n, 0, 0);
        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    Solution obj;
    vector<string> paths = obj.ratInMaze(maze);

    cout << "Possible paths:" << endl;
    for (const string &path : paths) {
        cout << path << endl;
    }

    return 0;
}