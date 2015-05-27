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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        
        if (preorder.size() != inorder.size())
            throw "Preorder's length must be equal to inorder's length.";
        
        TreeNode *root;
        
        buildTreeCore(&root, preorder, 0, inorder, 0, inorder.size() - 1);
        
        return root;
    }

private:
    void buildTreeCore(TreeNode **p, vector<int> &preorder, int preBegin, vector<int> &inorder, int inBegin, int inEnd) {
        if (preBegin == preorder.size())
            return;
        
        if (inBegin > inEnd)
            throw "Invalid range of inorder sequence";
        
        *p = new TreeNode(preorder[preBegin]);
        
        int inPartition = find(inorder, inBegin, inEnd, preorder[preBegin]);
        
        if (inPartition < 0)
            throw "Invalid inorder sequence";
        
        if (inBegin < inPartition)
            buildTreeCore(&(*p)->left, preorder, preBegin + 1, inorder, inBegin, inPartition - 1);
        
        if (inPartition < inEnd)
            buildTreeCore(&(*p)->right, preorder, preBegin + (inPartition - inBegin) + 1, inorder, inPartition + 1, inEnd);
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
