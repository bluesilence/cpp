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
        
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
        
        bool foundP = findPath(root, p, pathP);
        bool foundQ = findPath(root, q, pathQ);
        
        TreeNode* lca = NULL;
        
        if (foundP && foundQ) {
            int i = 0;
            while (i < pathP.size() && i < pathQ.size()) {
                if (pathP[i] != pathQ[i]) {
                    break;
                } else {
                    lca = pathP[i];
                    i++;
                }
            }
        }
        
        return lca;
    }

private:
    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*> &path) {
        if (!root)
            return false;
            
        path.push_back(root);
        
        if (root != p) {
            bool found = false;
            if (p->val < root->val) {
                found = findPath(root->left, p, path);
            } else {
                found = findPath(root->right, p, path);
            }
            
            if (!found) {
                path.pop_back();
                return false;
            }
        }
        
        return true;
    }
};
