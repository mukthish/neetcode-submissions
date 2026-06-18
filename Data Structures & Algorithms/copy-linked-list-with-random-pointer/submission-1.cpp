/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> mp;
        Node* old = head;
        Node* fresh = new Node(head->val);
        mp[head] = fresh;
        while (old) {
            // Add / create random
            if (old->random) {
                if (!mp.count(old->random)) {
                    mp[old->random] = new Node(old->random->val);
                }
                fresh->random = mp[old->random];
            }

            // Add / create next
            if (old->next) {
                if (!mp.count(old->next)) {
                    mp[old->next] = new Node(old->next->val);
                }
                fresh->next = mp[old->next];
            }

            // Updation
            old = old->next;
            fresh = fresh->next;
        }
        return mp[head];
    }
};
