#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int maxi = INT_MIN;
            while (n--) {
                TreeNode* tmp = q.front();
                q.pop();
                maxi = max(maxi, tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

// Optional: Function to build and test the tree
int main() {
    TreeNode* root = new TreeNode(1,
        new TreeNode(3, new TreeNode(5), new TreeNode(3)),
        new TreeNode(2, nullptr, new TreeNode(9))
    );

    Solution sol;
    vector<int> res = sol.largestValues(root);

    for (int val : res) {
        cout << val << " ";
    }

    // Clean up memory (not necessary in contests but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
