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
    int dfs(TreeNode* root, int currMax) {
        if (!root) {
            return 0;
        }
        int good = 0;
        if (root->val >= currMax) {
            currMax = root->val;
            good = 1;
        }
        return dfs(root->left, currMax) + dfs(root->right, currMax) + good;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, -101);
    }
};
