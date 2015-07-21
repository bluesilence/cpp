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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q)
            return true;
        
        if (!p || !q)
            return false;
        
        TreeNode* iterP = p;
        TreeNode* iterQ = q;
        stack<TreeNode*> stackP;
        stack<TreeNode*> stackQ;
    
        while (iterP && iterQ || !stackP.empty() && !stackQ.empty()) {
            while (iterP && iterQ) {
                if (iterP->val != iterQ->val) {
                    return false;
                }
                
                stackP.push(iterP);
                stackQ.push(iterQ);
                
                iterP = iterP->left;
                iterQ = iterQ->left;
            }
            
            if (iterP != NULL || iterQ != NULL)
                return false;
            
            if (!stackP.empty() && !stackQ.empty()) {
                iterP = stackP.top();
                stackP.pop();
                
                iterP = iterP->right;
                
                iterQ = stackQ.top();
                stackQ.pop();
                
                iterQ = iterQ->right;
            }
        }
        
        return true;
    }
};
