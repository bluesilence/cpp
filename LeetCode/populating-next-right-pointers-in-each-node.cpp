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
        //Level order traversal. Preserve the last node of the same level.
        //When visiting the current node, set it to be the next node of last node.
        //When reaching the end of current level, set the last node's next node to be NULL.
        if (!root)
            return;
        
        TreeLinkNode *pre = NULL;
        TreeLinkNode *p = NULL;
        
        queue<TreeLinkNode *> q;
        
        q.push(root);
        q.push(NULL);
        
        while (!q.empty()) {
            p = q.front();
            q.pop();
            
            if (pre != NULL) {
                pre->next = p;
            }
            
            pre = p;    //Including NULL, so that the pre to next level is set to p from NULL, and L32 could be reached
            
            if (p != NULL) {
                if (p->left)
                    q.push(p->left);
                
                if (p->right)
                    q.push(p->right);
            } else {
                if (!q.empty()) //There are more levels to be visited in the queue
                    q.push(NULL);
            }
        }
    }
};
