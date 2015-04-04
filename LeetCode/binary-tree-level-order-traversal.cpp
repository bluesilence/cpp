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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        //Track the count for each level in the queue
        int currentLevelCount = 1;
        int nextLevelCount = 0;
        vector<int> tmp;
        
        while(!q.empty()) {
            tmp.clear();
            nextLevelCount = 0;
            
            for (int i = 0; i < currentLevelCount; i++) {
                root = q.front();
                q.pop();
                
                tmp.push_back(root->val);
                if (root->left) {
                    q.push(root->left);
                    nextLevelCount++;
                }
                
                if (root->right) {
                    q.push(root->right);
                    nextLevelCount++;
                }
            }
            
            currentLevelCount = nextLevelCount;
            result.push_back(tmp);
        }
        
        return result;
    }
};
