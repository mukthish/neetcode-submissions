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
    bool isValidBST(TreeNode* root, int lo = -1001, int hi = 1001) {
        if (!root) {
            return true;
        }
        return root->val < hi and root->val > lo and isValidBST(root->left, lo, root->val) and isValidBST(root->right, root->val, hi);
    }
};
