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
    vector<int> rightSideView(TreeNode *root) {
        //Get the last node at each level
        vector<int> nodes;
        if (!root)
            return nodes;
        
        nodes.push_back(root->val);
        
        queue<TreeNode*> q;
        q.push(root);
        
        //Track the count for each level in the queue
        int currentLevelCount = 1;
        int nextLevelCount = 0;
        TreeNode *lastNodeInLevel;
        
        while(!q.empty()) {
            nextLevelCount = 0;
            lastNodeInLevel = NULL;
            for (int i = 0; i < currentLevelCount; i++) {
                root = q.front();
                q.pop();
                
                if (root->left) {
                    q.push(root->left);
                    lastNodeInLevel = root->left;
                    nextLevelCount++;
                }
                
                if (root->right) {
                    q.push(root->right);
                    lastNodeInLevel = root->right;
                    nextLevelCount++;
                }
            }
            
            currentLevelCount = nextLevelCount;
            if (lastNodeInLevel != NULL)
                nodes.push_back(lastNodeInLevel->val);
        }
        
        return nodes;
    }
};
