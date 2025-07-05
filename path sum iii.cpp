#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int solve(TreeNode* root, int t, long long s, unordered_map<long long, long long>& mp) {
        if (!root) return 0;

        s += root->val;
        int cnt = mp[s - t];
        mp[s]++;
        cnt += solve(root->left, t, s, mp);
        cnt += solve(root->right, t, s, mp);
        mp[s]--;

        return cnt;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, long long> mp;
        mp[0] = 1;
        return solve(root, targetSum, 0, mp);
    }
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < nodes.size()) {
        TreeNode* curr = q.front(); q.pop();
        if (nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    vector<string> nodes = {"10","5","-3","3","2","null","11","3","-2","null","1"};
    int targetSum = 8;

    TreeNode* root = buildTree(nodes);
    Solution sol;
    int result = sol.pathSum(root, targetSum);

    cout << result << endl;
    return 0;
}

