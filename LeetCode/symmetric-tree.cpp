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
        //Symmetric is not equality on the left and right child
        //It means left's left child equals to right's right child, and left's right child equals to right's left child
        if (!root)
            return true;
            
        return isSymCore(root->left, root->right);
    }

private:
    bool isSymCore(TreeNode *p1, TreeNode *p2) {
        if (!p1 && !p2)
            return true;
        
        if (!p1 || !p2)
            return false;
        
        return isSymCore(p1->left, p2->right) && isSymCore(p1->right, p2->left) && p1->val == p2->val;
    }
};
