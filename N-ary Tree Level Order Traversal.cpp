#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> v;
            
            for (int i = 0; i < n; i++) {
                Node* tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                
                for (Node* child : tmp->children) {
                    q.push(child);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};

int main() {
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    vector<Node*> children3 = {node5, node6};
    Node* node3 = new Node(3, children3);
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    vector<Node*> children1 = {node3, node2, node4};
    Node* root = new Node(1, children1);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    delete node5;
    delete node6;
    delete node3;
    delete node2;
    delete node4;
    delete root;

    return 0;
}
