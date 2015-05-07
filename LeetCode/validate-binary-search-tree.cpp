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
        
        if (pre != NULL && pre->val >= root->val)
            return false;
        
        pre = root;
        
        if (root->right)
            return isValidBST(root->right);
        else
            return true;
    }

private:
    TreeNode *pre;
};
