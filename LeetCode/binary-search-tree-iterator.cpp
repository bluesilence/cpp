/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        inOrderTraverse(root);
        current = 0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current < inOrderTraversal.size();
    }

    /** @return the next smallest number */
    int next() {
        return inOrderTraversal[current++]->val;
    }

private:
    vector<TreeNode*> inOrderTraversal;
    int current;
    
    void inOrderTraverse(TreeNode* root) {
        if (!root)
            return;
        
        inOrderTraverse(root->left);
        
        inOrderTraversal.push_back(root);
        
        inOrderTraverse(root->right);
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
