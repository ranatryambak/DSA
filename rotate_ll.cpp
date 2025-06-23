#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* tmp = &dummy;
        tmp = tmp->next;
        if (head == NULL || head->next == NULL) return head;
        while (tmp != NULL) {
            tmp = tmp->next;
            n++;
        }
        int a = k % n;
        if (a == 0) return head;
        ListNode* curr = head;
        ListNode* prev = head;
        for (int i = 0; i < n - a; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        ListNode* ans = curr;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = dummy.next;
        return ans;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution sol;
    ListNode* rotated = sol.rotateRight(head, k);
    printList(rotated);

    return 0;
}
