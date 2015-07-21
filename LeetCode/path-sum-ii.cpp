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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        
        if (!root)
            return paths;
        
        vector<int> path;
        
        findPath(paths, path, root, sum);
        
        return paths;
    }

private:
    void findPath(vector<vector<int>>& paths, vector<int>& path, TreeNode* p, int sum) {
        if (!p)
            return;
        
        sum -= p->val;
        path.push_back(p->val);
        
        if (sum == 0 && !p->left && !p->right) {
            paths.push_back(path);
        } else {
            if (p->left)
                findPath(paths, path, p->left, sum);
            
            if (p->right)
                findPath(paths, path, p->right, sum);
        }
        
        path.pop_back();
        sum += p->val;
    }
};
