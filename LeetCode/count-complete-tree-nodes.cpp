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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        
        int rightDepth = countRightDepth(root);
        int leftDepth = countLeftDepth(root);
        
        if (rightDepth == leftDepth) {
            int count = 0;
            for (int i = 0; i <= leftDepth; i++) {
                count += pow(2, i);
            }
            
            return count;
        } else {
            return countNodes(root->right) + countNodes(root->left) + 1;
        }
    }
    
private:
    int countLeftDepth(TreeNode *root) {
        if (!root)
            return 0;
        
        int depth = 0;
        while (root && root->left) {
            depth++;
            root = root->left;
        }
        
        return depth;
    }
    
    int countRightDepth(TreeNode *root) {
        if (!root)
            return 0;
        
        int depth = 0;
        while (root && root->right) {
            depth++;
            root = root->right;
        }
        
        return depth;
    }
};
