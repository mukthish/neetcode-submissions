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
    bool isSame(TreeNode* tree1, TreeNode* tree2) {
        if (!tree1 and !tree2) {
            return true;
        } else if (!tree1 or !tree2) {
            return false;
        }
        return tree1->val == tree2->val and isSame(tree1->left, tree2->left) and isSame(tree1->right, tree2->right); 
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        return isSame(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};
