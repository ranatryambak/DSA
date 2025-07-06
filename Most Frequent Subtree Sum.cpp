#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
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
    int solve(TreeNode* root, unordered_map<int, int>& mp, int& cnt) {
        if (!root) return 0;
        int a = solve(root->left, mp, cnt) + solve(root->right, mp, cnt) + root->val;
        mp[a]++;
        cnt = max(cnt, mp[a]);
        return a;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        int cnt = 0;
        unordered_map<int, int> mp;
        solve(root, mp, cnt);
        vector<int> res;
        for (auto& it : mp) {
            if (it.second == cnt) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};

// Helper to build a simple binary tree
TreeNode* buildSimpleTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildSimpleTree();

    vector<int> result = sol.findFrequentTreeSum(root);

    cout << "Most frequent subtree sum(s): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
