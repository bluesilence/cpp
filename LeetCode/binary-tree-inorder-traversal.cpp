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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        
        if (!root)
            return results;
        
        TreeNode* p = root;
        TreeNode* pre = NULL;
        
        //Iterative, non-stack way: Put parent node at the end of its left subtree, traverse left subtree, then visit parent
        while (p) {
            if (p->left) {
                pre = p->left;
                while (pre->right && pre->right != p) {
                    pre = pre->right;
                }
                
                if (!pre->right) {
                    pre->right = p; //Link p to the end of its left subtree
                    p = p->left;
                } else {    //All left nodes of p have been visited, the next node circles back to p
                    results.push_back(p->val);
                    pre->right = NULL;  //Revert the change
                    p = p->right;
                }
            } else {
                results.push_back(p->val);
                p = p->right;
            }
        }
        
        return results;
    }
};
