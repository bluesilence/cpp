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
        vector<vector<int> > results;
        if (!root)
            return results;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(0);  //Mark of the end of level
        
        TreeNode *tmp;
        vector<int> level;
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            
            if (tmp == 0) {
                if (!level.empty()) {   //At the end of the traversal, there will be 2 adjacent 0s, and level will be empty then
                    results.push_back(level);
                    level.clear();
                }
            } else {
                level.push_back(tmp->val);
                if (tmp->left) {
                    q.push(tmp->left);
                }
                
                if (tmp->right) {
                    q.push(tmp->right);
                }
                
                if (q.front() == 0) {   //Reached the end of current level, insert the terminator for the next level
                    q.push(0);
                }
            }
        }
        
        return results;
    }
};
