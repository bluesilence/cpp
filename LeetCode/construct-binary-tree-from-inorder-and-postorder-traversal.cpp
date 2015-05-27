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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return NULL;
        
        if (inorder.size() != postorder.size())
            throw "The length of inorder and postorder sequences must be the same.";
            
        TreeNode *root = new TreeNode(0);
        buildTreeCore(root, inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
        
        return root;
    }

private:
    void buildTreeCore(TreeNode *root, vector<int> &inorder, int inBegin, int inEnd, vector<int> &postorder, int postEnd) {
        if (postEnd < 0)
            return;
        
        root->val = postorder[postEnd];
        
        int inPartition = find(inorder, inBegin, inEnd, root->val);
        
        if (inPartition >= 0) {
            if (inBegin < inPartition) {
                root->left = new TreeNode(0);
                buildTreeCore(root->left, inorder, inBegin, inPartition - 1, postorder, postEnd - (inEnd - inPartition) - 1);
            }
            
            if (inPartition < inEnd) {
                root->right = new TreeNode(0);
                buildTreeCore(root->right, inorder, inPartition + 1, inEnd, postorder, postEnd - 1);
            }
        }
    }
    
    int find(vector<int> &nums, int begin, int end, int target) {
        if (begin < 0 || end >= nums.size())
            return -1;
            
        for (int i = begin; i <= end; i++) {
            if (nums[i] == target)
                return i;
        }
        
        return -1;
    }
};
