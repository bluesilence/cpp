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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> results;
        
        if (!root)
            return results;
        
        vector<int> result;
        pathSumCore(results, result, root, sum);
    }

private:
    void pathSumCore(vector<vector<int>> &results, vector<int> &result, TreeNode *root, int sum) {
        if (!root)
            return;
        
        result.push_back(root->val);
        
        if (!root->left && !root->right) {
            if (root->val == sum) {
                results.push_back(result);
            }
        } else {
            if (root->left) {
                pathSumCore(results, result, root->left, sum - root->val);
            }
            
            if (root->right) {
                pathSumCore(results, result, root->right, sum - root->val);
            }
        }
        
        result.pop_back();
    }
};
