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
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        
        long long sum = 0;
        
        sumNumbersCore(root, sum, 0);
        
        if (sum > numeric_limits<int>::max())
            return numeric_limits<int>::max();
        else
            return sum;
    }

private:
    void sumNumbersCore(TreeNode *node, long long &sum, long long num) {
        num += node->val;
        
        if (!node->left && !node->right) {  //Leaf node
            sum += num;
            return;
        }
        
        if (node->left) {
            sumNumbersCore(node->left, sum, num * 10);
        }
        
        if (node->right) {
            sumNumbersCore(node->right, sum, num * 10);
        }
    }
};
