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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if (!root)
            return results;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> result;
        
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            
            if (tmp == NULL) {
                if (!q.empty()) {
                    q.push(NULL);
                }
                
                results.push_back(result);
                result.clear(); //Clear previous result for next level
            } else {
                result.push_back(tmp->val);
                if (tmp->left) {
                    q.push(tmp->left);
                }
                    
                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
        }
        
        reverse(results.begin(), results.end());
        
        return results;
    }
};
