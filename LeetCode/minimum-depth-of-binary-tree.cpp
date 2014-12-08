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
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
            
        int lDepth = minDepth(root->left);
        int rDepth = minDepth(root->right);
        
        int depth = 1;
        if (lDepth == 0)   //No left child
            depth += rDepth;
        else if (rDepth == 0)  //No right child
            depth += lDepth;
        else    //Select min depth from two children
            depth += lDepth < rDepth ? lDepth : rDepth;
        
        return depth;
    }
};
