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
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        
        return isSymCore(root->left, root->right);
    }
    
private:
    bool isSymCore(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2)
            return true;
        
        if (!t1 || !t2)
            return false;
            
        return isSymCore(t1->left, t2->right) && isSymCore(t1->right, t2->left) && t1->val == t2->val;
    }
};
