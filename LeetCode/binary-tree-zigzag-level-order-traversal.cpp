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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //Similar to level order traversal. Use a flag to indicate traversing left to right or right to left.
        vector<vector<int>> results;
        
        if (!root)
            return results;
        
        vector<int> result;
        TreeNode *dummy = new TreeNode(0);
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(dummy);
        
        TreeNode *tmp;
        bool isLeftToRight = true; //The order to push children of the nodes of current level
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            
            if (tmp == dummy) { //Enter next level
                if (!q.empty()) //Is there any node at next level
                    q.push(dummy);  //The end of children of current level
                    
                if (!isLeftToRight)
                    reverse(result.begin(), result.end());
                
                results.push_back(result);
                result.clear();
                
                isLeftToRight = !isLeftToRight;
                
                continue;
            }
            
            result.push_back(tmp->val);
            
            if (tmp->left)
                q.push(tmp->left);
                
            if (tmp->right)
                q.push(tmp->right);
        }
        
        return results;
    }
};
