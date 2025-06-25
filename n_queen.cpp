#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(int n, vector<vector<char>> &a, int row, int col) {
        for (int i = 0; i < col; i++) {
            if (a[row][i] == 'Q') return false;
        }
        int x = row;
        int y = col;
        while (y >= 0 && x < n) {
            if (a[x][y] == 'Q') return false;
            x++;
            y--;
        }
        x = row;
        y = col;
        while (x >= 0 && y >= 0) {
            if (a[x][y] == 'Q') return false;
            x--;
            y--;
        }
        return true;
    }

    void addans(int n, vector<vector<char>> &b, vector<vector<string>> &a) {
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string tmp = "";
            for (int j = 0; j < n; j++) {
                tmp += b[i][j];
            }
            v.push_back(tmp);
        }
        a.push_back(v);
    }

    void solve(int col, int n, vector<vector<string>> &a, vector<vector<char>> &board) {
        if (col == n) {
            addans(n, board, a);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (check(n, board, row, col)) {
                board[row][col] = 'Q';
                solve(col + 1, n, a, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(0, n, ans, board);
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<string>> res = sol.solveNQueens(n);
    for (auto &soln : res) {
        for (auto &row : soln) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
