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
    void recoverTree(TreeNode *root) {
        TreeNode* first = NULL;  //First wrong node
        TreeNode* mid = NULL;  //The node that is the next node to first in an InOrderTraversal.
        TreeNode* second = NULL;  //Second wrong node
        TreeNode* prev = NULL;  //Previous node to root in an InOrderTraversal. Used to determine if root is disordered
        recorverTreeUtil(root, prev, first, mid, second);  
        
        if(second != NULL)
            swap(first->val, second->val);  
        else    //Only 1 disorder. The 2 nodes are adjacent
            swap(first->val, mid->val);  
    }

private:
    void recorverTreeUtil(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& mid, TreeNode*& second) {  
        if(!root)
            return;
            
        recorverTreeUtil(root->left, prev, first, mid, second);  
        if(prev != NULL && prev->val > root->val) {  
            if(!first) {
                first = prev;
                mid = root;  
            } else {
                second = root;
            }
        }
        
        prev = root;  
        recorverTreeUtil(root->right, prev, first, mid, second);  
    }
};
