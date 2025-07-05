#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<int, int> solve(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int take = root->val + left.second + right.second;
        int ntake = max(left.first, left.second) + max(right.first, right.second);

        return {take, ntake};
    }

    int rob(TreeNode* root) {
        pair<int, int> res = solve(root);
        return max(res.first, res.second);
    }
};

// Utility to create a simple test tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree();

    cout << "Maximum money that can be robbed: " << sol.rob(root) << endl;

    return 0;
}
