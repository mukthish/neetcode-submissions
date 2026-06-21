/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            int n = q.size();
            vector<int> curr;
            while (n--) {
                curr.push_back(q.front()->val);
                TreeNode* left = q.front()->left;
                TreeNode* right = q.front()->right;
                if (left) {
                    q.push(left);
                }
                if (right) {
                    q.push(right);
                }
                q.pop();
            }
            res.push_back(curr);
        }
        return res;
    }
};
