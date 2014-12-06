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
    int maxPathSum(TreeNode *root) {
        int max = numeric_limits<int>::min();
        maxPathSumCore(root, max);
        
        return max;
    }
    
private:
    int maxPathSumCore(TreeNode *root, int &maximum) {
        if (!root)
            return 0;
            
        int lMax = root->left ? maxPathSumCore(root->left, maximum) : 0;
        int rMax = root->right ? maxPathSumCore(root->right, maximum) : 0;
        
        int sum = root->val;
        if (lMax > 0)
            sum += lMax;
        
        if (rMax > 0)
            sum += rMax;
            
        maximum = max(maximum, sum);
        
        return max(lMax, rMax) > 0 ? (max(lMax, rMax) + root->val) : root->val;
    }
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
};
