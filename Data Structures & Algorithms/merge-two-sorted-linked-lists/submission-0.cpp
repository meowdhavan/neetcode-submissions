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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur = new ListNode();
        ListNode *newHead = cur;

        while (list1 != nullptr || list2 != nullptr) {
            bool addSecond = false;

            if (list1 != nullptr && list2 != nullptr) {
                if (list1->val > list2->val) {
                    addSecond = true;
                }
            } else if (list2 != nullptr) {
                addSecond = true;
            }

            ListNode *newNode = new ListNode();

            if (addSecond) {
                newNode->val = list2->val;
                list2 = list2->next;
            } else {
                newNode->val = list1->val;
                list1 = list1->next;
            }

            cur->next = newNode;
            cur = newNode;
        }

        return newHead->next;
    }
};
