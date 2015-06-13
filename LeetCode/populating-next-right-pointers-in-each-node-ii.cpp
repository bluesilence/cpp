/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        
        queue<TreeLinkNode*> q;
        TreeLinkNode *pre = NULL;
        
        q.push(root);
        q.push(NULL);
        
        while (!q.empty()) {
            TreeLinkNode *tmp = q.front();
            q.pop();
            
            if (pre != NULL) {
                pre->next = tmp;
            }
            
            if (tmp == NULL) {
                if (!q.empty()) {   //There are more layers to visit
                    pre = NULL;
                
                    q.push(NULL);  //Insert terminator of next layer
                }
            } else {
                pre = tmp;
                
                if (tmp->left) {
                    q.push(tmp->left);
                }
            
                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
        }
    }
};
