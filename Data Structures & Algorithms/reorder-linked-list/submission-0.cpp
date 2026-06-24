/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;

        ListNode *mid = head;
        ListNode *fast = head->next;

        while (mid != nullptr && fast != nullptr && fast->next != nullptr) {
            mid = mid->next;
            fast = fast->next->next;
        }

        ListNode *cur = mid->next;
        ListNode *prev = nullptr;
        mid->next = nullptr;

        while (cur != nullptr) {
            ListNode *newNext = cur->next;

            cur->next = prev;
            prev = cur;
            cur = newNext;
        }

        // while (head != nullptr) {
        //     cout << head->val << " ";
        //     head = head->next;
        // }
        // cout << endl;

        // while (prev != nullptr) {
        //     cout << prev->val << " ";
        //     prev = prev->next;
        // }
        // cout << endl;

        ListNode *first = head;
        ListNode *second = prev;

        while (second != nullptr) {
            ListNode *nextHead = head->next;
            ListNode *nextSecond = second->next;

            head->next = second;
            second->next = nextHead;

            head = nextHead;
            second = nextSecond;
        }
    }
};
