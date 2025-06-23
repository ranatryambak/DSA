#include <iostream>
#include <map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        map<Node*, Node*> mp;
        Node* tmp = head;
        while (tmp) {
            Node* a = new Node(tmp->val);
            mp[tmp] = a;
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp) {
            Node* ans = mp[tmp];
            ans->next = mp[tmp->next];
            ans->random = mp[tmp->random];
            tmp = tmp->next;
        }
        return mp[head];
    }
};

// Helper to print the copied list
void printList(Node* head) {
    while (head) {
        cout << "Value: " << head->val;
        if (head->random)
            cout << ", Random: " << head->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        head = head->next;
    }
}

int main() {
    // Create original list: 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2;
    n2->next = n3;

    // Set random pointers
    n1->random = n3;  // 1's random points to 3
    n2->random = n1;  // 2's random points to 1
    n3->random = n2;  // 3's random points to 2

    Solution sol;
    Node* copiedHead = sol.copyRandomList(n1);

    cout << "Copied list:\n";
    printList(copiedHead);

    return 0;
}
