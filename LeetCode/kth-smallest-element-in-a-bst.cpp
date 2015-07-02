class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return binarySearch(root, k);
    }

private:
    int binarySearch(TreeNode *root, int &k) {
        if (root) {
            int result = binarySearch(root->left, k);
            //--k is necessary here, since k must substract current node before return
            return k == 0 ? result : (--k == 0 ? root->val : binarySearch(root->right, k));
        }
        
        return 0;
    }
};
