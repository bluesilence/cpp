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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> results;
        
        if (!root)
            return results;
            
        queue<TreeNode*> s1, s2;
        s1.push(root);
        
        TreeNode *p = NULL;
        vector<int> levelResult;
        while (!s1.empty() || !s2.empty()) {
            levelResult.clear();
            
            //one of s1, s2 must be empty
            if (!s1.empty()) {
                while (!s1.empty()) {
                    p = s1.front();
                    s1.pop();
                    levelResult.push_back(p->val);
                    if (p->left)
                        s2.push(p->left);
                    
                    if (p->right)
                        s2.push(p->right);
                }
            } else {
                while (!s2.empty()) {
                    p = s2.front();
                    s2.pop();
                    levelResult.push_back(p->val);
                    if (p->left)
                        s1.push(p->left);
                    
                    if (p->right)
                        s1.push(p->right);
                }
            }
            
            results.push_back(levelResult);
        }
        
        return results;
    }
};
