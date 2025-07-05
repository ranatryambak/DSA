#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        Node* levelStart = root;

        // Traverse level by level
        while (levelStart->left) {
            Node* curr = levelStart;

            // Connect all nodes at the current level
            while (curr) {
                curr->left->next = curr->right;
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }

            // Move to the next level
            levelStart = levelStart->left;
        }

        return root;
    }
};

// Helper function to print next pointers at each level
void printNextPointers(Node* root) {
    Node* level = root;
    while (level) {
        Node* curr = level;
        while (curr) {
            cout << curr->val << " -> ";
            if (curr->next) cout << curr->next->val << " ";
            else cout << "NULL ";
            curr = curr->next;
        }
        cout << endl;
        level = level->left;
    }
}

int main() {
    // Building a perfect binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    Node* connectedRoot = sol.connect(root);

    cout << "Next pointers level by level:\n";
    printNextPointers(connectedRoot);

    return 0;
}
