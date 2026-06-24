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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *behind = new ListNode(0, head);
        ListNode *start = behind;
        ListNode *ahead = head;

        // n = 2
        //       V
        // 0 1 2 3 4 X
        //     ^     ^

        // n = 1
        //   V
        // 0 5 X
        // ^   ^

        for (int i = 0; i < n; ++i) {
            ahead = ahead->next;
        }

        while (ahead != nullptr) {
            behind = behind->next;
            ahead = ahead->next;
        }

        behind->next = behind->next->next;

        return start->next;
    }
};
