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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        //Level-order traverse + a flag to indicate whether to reverse sequence within a level
        vector<vector<int>> results;
        
        if (!root)
            return results;
            
        q1.push(root);
        while (!q1.empty() || !q2.empty()) {
            vector<int> level;
            if (!q1.empty()) {
                while (!q1.empty()) {
                    TreeNode *tmp = q1.front();
                    q1.pop();
                    level.push_back(tmp->val);
                    if (tmp->left)
                        q2.push(tmp->left);
                    
                    if (tmp->right)
                        q2.push(tmp->right);
                }
            } else {
                while (!q2.empty()) {
                    TreeNode *tmp = q2.front();
                    q2.pop();
                    level.push_back(tmp->val);
                    if (tmp->left)
                        q1.push(tmp->left);
                    
                    if (tmp->right)
                        q1.push(tmp->right);
                }
            }
                
            if (flag) {
                reverse(level.begin(), level.end());
            }
                
            flag = !flag;
                
            results.push_back(level);
        }
        
        return results;
    }

private:
    queue<TreeNode*> q1, q2;
    bool flag;
};
