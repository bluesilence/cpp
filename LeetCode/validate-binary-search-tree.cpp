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
        
        stack<TreeNode*> s;
        TreeNode* p = root;
        TreeNode* pre = NULL;
        
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            
            if (!s.empty()) {
                p = s.top();
                s.pop();
                
                if (pre != NULL) {
                    if (pre->val >= p->val) {
                        return false;
                    }
                }
                
                pre = p;
                
                p = p->right;
            }
        }
        
        return true;
    }
};
