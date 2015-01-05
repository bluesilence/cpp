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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        //Get the root node from postorder
        //Find root in inorder
        //Recursively build left and right trees
        if (postorder.empty() || inorder.empty()) {
            return NULL;
        } else {
            TreeNode *root = new TreeNode(0);
            int postIndex = postorder.size() - 1;
            buildCore(postorder, inorder, root, 0, inorder.size() - 1, postIndex);
            return root;
        }
    }

private:
    //start, end: the range of inorder array
    //postIndex: the next node in postorder array to be constructed
    void buildCore(vector<int> &postorder, vector<int> &inorder, TreeNode *root, int start, int end, int &postIndex) {
        if (postIndex < 0 || start > end || !root)
            return;
        
        root->val = postorder[postIndex--];
        int index = find(inorder, start, end, root->val);
        if (-1 != index) {
            //Need to build right subtree first, because in postorder, the adjacent nodes to root is right nodes
            if (end > index) {    //There is right subtree to build
                root->right = new TreeNode(0);
                buildCore(postorder, inorder, root->right, index + 1, end, postIndex);
            }
            
            if (start < index) {    //There is left subtree to build
                root->left = new TreeNode(0);
                buildCore(postorder, inorder, root->left, start, index - 1, postIndex);
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
