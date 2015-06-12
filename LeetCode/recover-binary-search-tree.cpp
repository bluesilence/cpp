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
    void recoverTree(TreeNode* root) {
        if (!root)
            return;
        
        TreeNode *pre = NULL;
        TreeNode *firstWrongNode = NULL;
        TreeNode *secondWrongNode = NULL;
        TreeNode *postFirstWrongNode = NULL;
        
        findWrongNodes(root, pre, firstWrongNode, secondWrongNode, postFirstWrongNode);
        
        if (!secondWrongNode) {
            swap(firstWrongNode, postFirstWrongNode);
        } else {
            swap(firstWrongNode, secondWrongNode);
        }
    }

private:
    void findWrongNodes(TreeNode *root, TreeNode *&pre, TreeNode *&firstWrongNode, TreeNode *&secondWrongNode, TreeNode *&postFirstWrongNode) {
        if (!root)
            return;
        
        if (root->left)
            findWrongNodes(root->left, pre, firstWrongNode, secondWrongNode, postFirstWrongNode);
        
        if (pre != NULL && pre->val > root->val)    {//Found wrong node since it caused descending order
            if (!firstWrongNode) {
                firstWrongNode = pre;
                //Why don't assign it to "secondWrongNode"?
                //Because we don't know if there is a second wrong node(descending order) besides this pair of disordered nodes.
                postFirstWrongNode = root;
            } else {
                secondWrongNode = root;
            }
        }
        
        pre = root; //Update pre before traversing root's right child
        
        if (root->right)
            findWrongNodes(root->right, pre, firstWrongNode, secondWrongNode, postFirstWrongNode);
    }
    void swap(TreeNode *p1, TreeNode *p2) {
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }
};
