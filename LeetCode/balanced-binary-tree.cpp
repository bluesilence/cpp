/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        
        return isBalancedCore(root, height);
    }

private:
    bool isBalancedCore(TreeNode *root, int &height) {
        if (!root) {
            height = 0;
            return true;
        }
        
        int leftHeight = 0;
        bool leftIsBalanced = isBalancedCore(root->left, leftHeight);
        
        if (!leftIsBalanced)
            return false;
            
        int rightHeight = 0;
        bool rightIsBalanced = isBalancedCore(root->right, rightHeight);
        
        int heightDiff = leftHeight - rightHeight;
        
        height = max(leftHeight, rightHeight) + 1;
        
        return rightIsBalanced && (heightDiff >= -1 && heightDiff <= 1);
    }
};
