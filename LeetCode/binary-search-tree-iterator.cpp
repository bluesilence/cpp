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
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = s.top();
        s.pop();
        
        //Push the right subtree of tmp. These numbers are greater than tmp->val, but smaller than s.top()->val.
        pushLeft(tmp->right);
        
        return tmp->val;
    }

private:
    stack<TreeNode*> s;
    
    //The top of stack is always the next smallest number
    void pushLeft(TreeNode* root) {
        if (!root)
            return;
        
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
