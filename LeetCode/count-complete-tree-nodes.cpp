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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        
        int leftDepth = countLeftDepth(root);
        int rightDepth = countRightDepth(root);
        
        int count = 0;
        
        if (leftDepth == rightDepth) {
            count = pow(2, leftDepth) - 1;
        } else {
            count = countNodes(root->left) + countNodes(root->right) + 1;
        }
        
        return count;
    }
    
private:
    int countLeftDepth(TreeNode *root) {
        if (!root)
            return 0;
        
        if (!root->left)
            return 1;
        
        return countLeftDepth(root->left) + 1;
    }
    
    int countRightDepth(TreeNode *root) {
        if (!root)
            return 0;
        
        if (!root->right)
            return 1;
        
        return countRightDepth(root->right) + 1;
    }
};
