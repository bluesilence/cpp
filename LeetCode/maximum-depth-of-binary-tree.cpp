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
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
            
        int lDepth = root->left ? maxDepth(root->left) : 0;
        int rDepth = root->right ? maxDepth(root->right) : 0;
        
        return lDepth > rDepth ? (lDepth + 1) : (rDepth + 1);
    }
};
