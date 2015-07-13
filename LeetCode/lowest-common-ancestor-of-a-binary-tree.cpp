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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
            return NULL;
        
        if (p == q)
            return p;
            
        vector<TreeNode*> pathRootToP;
        vector<TreeNode*> pathRootToQ;
        
        bool foundP = findPath(pathRootToP, root, p);
        bool foundQ = findPath(pathRootToQ, root, q);
        
        TreeNode* lca = NULL;
        if (foundP && foundQ) {
            for (int i = 0; i < pathRootToP.size() && i < pathRootToQ.size(); i++) {
                if (pathRootToP[i] != pathRootToQ[i]) {
                    break;
                } else {
                    lca = pathRootToP[i];
                }
            }
        }
        
        return lca;
    }

private:
    bool findPath(vector<TreeNode*> &path, TreeNode* root, TreeNode* target) {
        if (!root)
            return false;
        
        path.push_back(root);
        
        if (root == target)
            return true;
        
        bool found = false;
        
        found = findPath(path, root->left, target);
        
        if (!found)
            found = findPath(path, root->right, target);
            
        if (!found)
            path.pop_back();
        
        return found;
    }
};
