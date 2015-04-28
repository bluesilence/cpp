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
    bool isValidBST(TreeNode *root) {
        if (!root)
            return true;
        
        if (root->left && !isValidBST(root->left))
            return false;
        
        if (pre != NULL && root->val <= pre->val)
            return false;
        
        pre = root;
        
        return isValidBST(root->right);
    }

private:
    TreeNode *pre;
};
