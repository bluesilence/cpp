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
        p = new TreeNode(0);    //Dummy head
        p->right = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        /*
         * If p has right child, the next node should be the most left bottom node in its right subtree
         * Else if p is the left child of its parent, the next node should be its parent node
         * Else, p is the right child of its parent, the next node should be the lowest parent which is the left child of its parent
         */
        if (p->right) {
            hierarchy.push(p);
            p = p->right;
            while (p && p->left) {
                hierarchy.push(p);
                p = p->left;
            }
        } else if (!hierarchy.empty()) {
            parent = hierarchy.top();
            hierarchy.pop();
            if (parent->left == p) {
                p = parent;
            } else {
                while (parent->left != p && !hierarchy.empty()) {
                    p = parent;
                    parent = hierarchy.top();
                    hierarchy.pop();
                };
                
                if (parent->left == p)
                    p = parent;
                else
                    p = NULL;
            }
        } else {
            p = NULL;
        }
        
        return p != NULL;
    }

    /** @return the next smallest number */
    int next() {
        return p->val;
    }

private:
    stack<TreeNode*> hierarchy;
    TreeNode *p, *parent;
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
