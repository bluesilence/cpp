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
    vector<int> postorderTraversal(TreeNode *root) {
        //Use a stack to record the sequence of nodes to be printed, and a stack to record the readiness of a node to be printed
        //A node can be printed after all its left and right children have been printed
        vector<int> results;
        
        stack<TreeNode*> nodeStack;
        stack<bool> readyStack;
        TreeNode *node = root;
        
        while (NULL != node || !nodeStack.empty()) {
            //Push root and it's left children into stack to form an output sequence
            while (NULL != node) {
                nodeStack.push(node);
                readyStack.push(false);
                node = node->left;
            }
            
            //Output all the ready-for-output nodes in the stack
            while (!nodeStack.empty() && readyStack.top() == true) {
                TreeNode *tmp = nodeStack.top();
                results.push_back(tmp->val);
                nodeStack.pop();
                readyStack.pop();
            }
            
            //All the left subtree has been outputed, ready to output the parent node.
            //But before that, let's traverse its right subtree
            if (!nodeStack.empty()) {
                readyStack.pop();
                readyStack.push(true);
                node = nodeStack.top()->right;
            }
        }
        
        return results;
    }
};
