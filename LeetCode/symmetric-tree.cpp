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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* p1, TreeNode* p2) {
        if (!p1 && !p2)
            return true;
        
        if (!p1 || !p2)
            return false;
            
        if (p1->val != p2->val)
            return false;
        
        return isMirror(p1->left, p2->right) && isMirror(p1->right, p2->left);
    }
};
