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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;

        for (auto node : lists) {
            pq.push(node);
        }

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            curr->next = node;
            node = node->next;
            curr->next->next = nullptr;
            curr = curr->next;
            if (node) {
                pq.push(node);
            }
        }      

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
