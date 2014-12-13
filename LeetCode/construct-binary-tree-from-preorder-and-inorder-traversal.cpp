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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        //Get the root node from preorder
        //Find root in inorder
        //Recursively build left and right trees
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        } else {
            TreeNode *root = new TreeNode(0);
            int preIndex = 0;
            buildCore(preorder, inorder, root, 0, inorder.size() - 1, preIndex);
            return root;
        }
    }

private:
    //start, end: the range of inorder array
    //preIndex: the next node in preorder array to be constructed
    void buildCore(vector<int> &preorder, vector<int> &inorder, TreeNode *root, int start, int end, int &preIndex) {
        if (preIndex >= preorder.size() || start > end || !root)
            return;
        
        root->val = preorder[preIndex++];
        int index = find(inorder, start, end, root->val);
        if (-1 != index) {
            if (start < index) {
                root->left = new TreeNode(0);
                buildCore(preorder, inorder, root->left, start, index - 1, preIndex);
            }
            
            if (end > index) {
                root->right = new TreeNode(0);
                buildCore(preorder, inorder, root->right, index + 1, end, preIndex);
            }
        }
    }
    
    int find(vector<int> &inorder, int start, int end, int target) {
        for (int i = start; i <= end; i++) {
            if (i >= inorder.size())
                break;
            
            if (inorder[i] == target)
                return i;
        }
        
        return -1;
    }
};
