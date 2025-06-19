#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) return ans;

        ans.push_back({1});
        for (int i = 1; i < numRows; i++) {
            vector<int> row(i + 1, 1); // first and last elements are 1
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};

// Optional main function to test
int main() {
    Solution sol;
    int numRows = 5;
    vector<vector<int>> result = sol.generate(numRows);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
