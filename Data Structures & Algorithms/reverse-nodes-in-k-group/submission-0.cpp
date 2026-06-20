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
    int length (ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l = length(head);
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy, *curr, *next;
        dummy->next = head;

        while (l >= k) {
            curr = prev->next;
            next = curr->next;

            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            prev = curr;
            l-=k;
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
