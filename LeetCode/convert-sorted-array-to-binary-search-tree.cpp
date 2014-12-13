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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.empty())
            return NULL;
        
        TreeNode *root = new TreeNode(0);
        buildBST(root, num, 0, num.size() - 1);
        
        return root;
    }
    
private:
    void buildBST(TreeNode *root, vector<int> &num, int start, int end) {
        if (!root || start > end)
            return;
        
        int mid = (start + end) / 2;
        root->val = num[mid];
        if (mid > start) {
            root->left = new TreeNode(0);
            buildBST(root->left, num, start, mid - 1);
        }
        
        if (mid < end) {
            root->right = new TreeNode(0);
            buildBST(root->right, num, mid + 1, end);
        }
    }
};
