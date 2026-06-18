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
        ListNode* prev = nullptr, *fast = head;
        while (n--) {
            fast = fast->next;
        }
        while (fast) {
            if (!prev) {
                prev = head;
            } else {
                prev = prev->next;
            }
            fast = fast->next;
        }

        if (prev) {
            ListNode* temp = prev->next;
            prev->next = prev->next->next;
            delete temp;
            return head;
        } else {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
    }
};
