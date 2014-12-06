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
            
        //Level traverse
        queue<TreeLinkNode*> q1, q2;
        q1.push(root);
        
        TreeLinkNode* pre = NULL, *curr = NULL;
        while (!q1.empty() || !q2.empty()) {
            pre = NULL;
            if (q1.empty()) {
                while (!q2.empty()) {
                    curr = q2.front();
                    if (curr->left)
                        q1.push(curr->left);
                    
                    if (curr->right)
                        q1.push(curr->right);
                    
                    q2.pop();
                    if (pre) {
                        pre->next = curr;
                    }
                
                    pre = curr;
                }
            } else {
                 while (!q1.empty()) {
                    curr = q1.front();
                    if (curr->left)
                        q2.push(curr->left);
                    
                    if (curr->right)
                        q2.push(curr->right);
                    
                    q1.pop();
                    if (pre) {
                        pre->next = curr;
                    }
                
                    pre = curr;
                }
            }
                
            if (pre)
                pre->next = NULL;
        }
    }
};
