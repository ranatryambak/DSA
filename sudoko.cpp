class Solution {
public:
    // Function to check whether it's valid to place 'c' at board[row][col]
    bool valid(vector<vector<char>>& b, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row and column
            if (b[row][i] == c || b[i][col] == c) return false;
            // Check 3x3 subgrid
            if (b[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }

    // Backtracking function to solve the board
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (valid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // no valid digit for this cell
                }
            }
        }
        return true; // all cells are filled correctly
    }

    // Public function to trigger solving
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
