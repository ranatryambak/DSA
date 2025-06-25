#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool check(vector<vector<char>> &v, int x, int y, int i, string s, int n, int m) {
        if (i >= s.size()) return true;
        if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] != s[i] || v[x][y] == '#') return false;
        char c = v[x][y];
        v[x][y] = '#';
        bool top = check(v, x - 1, y, i + 1, s, n, m);
        bool bottom = check(v, x + 1, y, i + 1, s, n, m);
        bool left = check(v, x, y - 1, i + 1, s, n, m);
        bool right = check(v, x, y + 1, i + 1, s, n, m);
        v[x][y] = c;
        return (top || bottom || left || right);
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (check(board, i, j, 0, word, n, m)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << (sol.exist(board, word) ? "true" : "false") << endl;
    return 0;
}
