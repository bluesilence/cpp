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
    void flatten(TreeNode* root) {
        //Flatten the tree using pre-order traversal
        if (!root || !root->left && !root->right)
            return;
        
        flattenCore(root);
    }

private:
    TreeNode *flattenCore(TreeNode *root) {
        if (!root)
            return NULL;
        
        if (!root->left && !root->right)
            return root;
        
        TreeNode *pLeft = root->left;
        TreeNode *pRight = root->right;
        
        root->left = NULL;
        
        root->right = flattenCore(pLeft);
        
        TreeNode *p = root;
        while (p && p->right) {
            p = p->right;
        }
        
        p->right = flattenCore(pRight);
        
        return root;
    }
};
