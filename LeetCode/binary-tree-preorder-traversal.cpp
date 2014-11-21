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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> results;
        if(!root)
            return results;
        
        TreeNode *node = root;
        while(!s.empty() || NULL != node) {
            while(NULL != node) {
                //Record root nodes
                results.push_back(node->val);
                
                //Store right nodes in stack
                if(NULL != node->right)
                    s.push(node->right);
                
                //Prepare to traverse left nodes
                node = node->left;
            }
            
            if(!s.empty()) {
                node = s.top();
                s.pop();
            }
        }
        
        return results;
    }
    
private:
    stack<TreeNode*> s;
};