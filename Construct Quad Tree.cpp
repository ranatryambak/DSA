#include <iostream>
#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    bool check(const vector<vector<int>>& grid, int n, int x, int y) {
        int tmp = grid[x][y];
        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++) {
                if (grid[i][j] != tmp) return false;
            }
        }
        return true;
    }

    Node* solve(const vector<vector<int>>& grid, int n, int x, int y) {
        if (check(grid, n, x, y)) {
            return new Node(grid[x][y], true);
        }

        Node* root = new Node(0, false);

        root->topLeft = solve(grid, n / 2, x, y);
        root->topRight = solve(grid, n / 2, x, y + n / 2);
        root->bottomLeft = solve(grid, n / 2, x + n / 2, y);
        root->bottomRight = solve(grid, n / 2, x + n / 2, y + n / 2);

        return root;
    }

    Node* construct(const vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return nullptr;
        return solve(grid, n, 0, 0);
    }
};

// Utility to print the QuadTree in preorder
void printTree(Node* root, int depth = 0) {
    if (!root) return;

    string indent(depth * 2, ' ');
    if (root->isLeaf) {
        cout << indent << "Leaf(val=" << root->val << ")\n";
    } else {
        cout << indent << "Internal\n";
        printTree(root->topLeft, depth + 1);
        printTree(root->topRight, depth + 1);
        printTree(root->bottomLeft, depth + 1);
        printTree(root->bottomRight, depth + 1);
    }
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1}
    };

    Solution sol;
    Node* root = sol.construct(grid);
    cout << "QuadTree (Preorder Traversal):\n";
    printTree(root);

    return 0;
}
