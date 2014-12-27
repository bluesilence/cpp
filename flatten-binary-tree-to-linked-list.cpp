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
    void flatten(TreeNode *root) {
        if (!root || !root->left && !root->right)
            return;
        
        TreeNode *pre = NULL;
        flatternCore(root, pre);
    }
    
private:
    void flatternCore(TreeNode *root, TreeNode *& pre) {
        if (!root)
            return;
            
        if (pre)
            pre->right = root;
        
        pre = root;
        TreeNode *right = root->right;
        flatternCore(root->left, pre);
        flatternCore(right, pre);
        
        root->left = NULL;
    }
};
