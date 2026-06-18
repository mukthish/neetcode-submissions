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
        // Finding middle
        ListNode* slow = head, *fast = head;
        while (fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Splitting the list into two
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* first = head;

        // Reversing the second list
        ListNode* prev = nullptr;
        while (second) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        second = prev;

        // Merging both lists
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        while (first) {
            res->next = first;
            res = res->next;
            first = first->next;
            if (second) {
                res->next = second;
                res = res->next;
                second = second->next;
            }
        }
        
        head = dummy->next;
        delete dummy;
    }
};
