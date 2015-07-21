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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        
        //Use iterative pre-order traversal doesn't work, because the right pointer will be modified when flattening the tree
        //Use recursive way instead. Since it's pre-order, the flattened node will still be previous node
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* leftHead = root->left;
        TreeNode* rightHead = root->right;
        
        root->left = NULL;
        root->right = leftHead;
        
        if (leftHead) { //Attach right list after left list
            TreeNode* leftTail = leftHead;
            while (leftTail->right) {
                leftTail = leftTail->right;
            }
        
            leftTail->right = rightHead;
        } else {    //Attach right list after root
            root->right = rightHead;
        }
    }
};
