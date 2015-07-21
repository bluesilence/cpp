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
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* p = s.top();
        s.pop();
        
        //The nodes on the right subtree of p are greater than p, but less than current s.top()
        pushLeftNodes(p->right);
        
        return p->val;
    }

private:
    stack<TreeNode*> s;
    
    void pushLeftNodes(TreeNode* p) {
        if (!p)
            return;
        
        while (p) {
            s.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
