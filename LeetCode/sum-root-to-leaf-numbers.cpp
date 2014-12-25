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
    int sumNumbers(TreeNode *root) {
        long long sum = 0;
        if (!root)
            return sum;
        
        long long num = 0;
        sumCore(root, sum, num);
        
        if (sum > numeric_limits<int>::max())
            return numeric_limits<int>::max();
        else
            return (int)sum;
    }

private:
    void sumCore(TreeNode *root, long long &sum, long long &num) {
        if (!root) {
            sum += num;
            return;
        }
        
        int originalNum = num;
        num = num * 10 + root->val;
        
        if (root->left)
            sumCore(root->left, sum, num);
        if (root->right)
            sumCore(root->right, sum, num);
        
        if (!root->left && !root->right)    //Leaf node
            sum += num;
        
        num = originalNum;
    }
};
