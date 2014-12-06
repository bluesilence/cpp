/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int h = 0;
        return isBalancedCore(root, h);
    }

private:
    bool isBalancedCore(TreeNode *root, int &height) {
        if (!root) {
            height = 0;
            return true;
        }
        
        int lHeight = 0, rHeight = 0;
        bool lBalanced = isBalancedCore(root->left, lHeight);
        if (lBalanced) {
            bool rBalanced = isBalancedCore(root->right, rHeight);
            if (rBalanced && lHeight - rHeight <= 1 && rHeight - lHeight <= 1) {
                height = lHeight > rHeight ? (lHeight + 1) : (rHeight + 1);
                return true;
            }
        }
        
        return false;
    }
};
