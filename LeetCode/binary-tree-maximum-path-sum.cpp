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
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        
        int maxSum = numeric_limits<int>::min();
        
        maxPathSumCore(root, maxSum);
        
        return maxSum;
    }

private:
    //maxSum is the max of path sum within the subtree of root, which may be 2 sided
    //return value is the max of path sum on 1 side of root's subtrees, so that it could be used to form deeper path
    int maxPathSumCore(TreeNode *root, int &maxSum) {
        if (!root)
            return 0;
        
        int leftMax = maxPathSumCore(root->left, maxSum);
        int rightMax = maxPathSumCore(root->right, maxSum);
        
        int sum = root->val;
        if (leftMax > 0) {
            sum += leftMax;
        }
        
        if (rightMax > 0) {
            sum += rightMax;
        }
        
        maxSum = max(maxSum, sum);
        
        return root->val + (max(leftMax, rightMax) > 0 ? max(leftMax, rightMax) : 0);
    }
};
