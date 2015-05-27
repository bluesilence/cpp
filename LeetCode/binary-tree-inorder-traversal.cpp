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
        
        stack<TreeNode*> s;
        TreeNode *tmp = root;
        
        while (!s.empty() || tmp) {
            while (tmp) {
                s.push(tmp);
                tmp = tmp->left;
            }
            
            if (!s.empty()) {
                tmp = s.top();
                s.pop();
                
                results.push_back(tmp->val);
                
                tmp = tmp->right;
            }
        }
        
        return results;
    }
};
