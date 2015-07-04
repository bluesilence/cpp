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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                canVisitRoot.push(false);
                root = root->left;
            }
            
            //If canVisitRoot.top() == true, then all the subtrees of s have been visited (otherwise there will be false elements on top of canVisitRoot), so we can now push the top of s into results
            while (!s.empty() && canVisitRoot.top()) {
                root = s.top();
                s.pop();
                canVisitRoot.pop();
                
                results.push_back(root->val);
                root = NULL;    //Necessary: otherwise the outer loop will always have root != NULL
            }
            
            if (!s.empty()) {
                root = s.top();
                canVisitRoot.pop();
                canVisitRoot.push(true);
                
                root = root->right;
            }
        }
        
        return results;
    }

private:
    stack<TreeNode*> s;
    stack<bool> canVisitRoot;
};
