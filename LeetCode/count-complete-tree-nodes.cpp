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
        
        int leftDepth = 0;
        TreeNode *leftTree = root;
        while (leftTree) {
            leftDepth++;
            leftTree = leftTree->left;
        }
        
        int rightDepth = 0;
        TreeNode *rightTree = root;
        while (rightTree) {
            rightDepth++;
            rightTree = rightTree->right;
        }
        
        int count = 0;
        
        if (leftDepth == rightDepth) {
            count = (1 << leftDepth) - 1;
        } else {
            count = countNodes(root->left) + countNodes(root->right) + 1;
        }
        
        return count;
    }
};
