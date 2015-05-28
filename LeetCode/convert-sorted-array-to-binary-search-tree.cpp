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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;
            
        TreeNode *root = new TreeNode(0);
        
        transform(root, nums, 0, nums.size() - 1);
        
        return root;
    }

private:
    void transform(TreeNode *p, vector<int> &nums, int begin, int end) {
        if (begin > end || begin < 0 || end >= nums.size())
            return;
        
        int mid = (begin + end) / 2;
        p->val = nums[mid];
        
        if (begin < mid) {
            p->left = new TreeNode(0);
            transform(p->left, nums, begin, mid - 1);
        }
        
        if (mid < end) {
            p->right = new TreeNode(0);
            transform(p->right, nums, mid + 1, end);
        }
    }
};
