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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> results;
        
        while (root || !s.empty()) {
            while (root) {
                results.push_back(root->val);
                
                s.push(root);
                root = root->left;
            }
            
            if (!s.empty()) {
                root = s.top();
                s.pop();
                
                root = root->right;
            }
        }
        
        return results;
    }

private:
    stack<TreeNode*> s;
};
