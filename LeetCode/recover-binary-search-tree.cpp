/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (!root || !root->left && !root->right)
            return;
        
        TreeNode* p = root;
        TreeNode* pre = NULL;
        TreeNode* firstMistake = NULL;
        TreeNode* secondMistake = NULL;
        TreeNode* firstMistakeSuccessor = NULL;
        
        stack<TreeNode*> s;
        
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            
            if (!s.empty()) {
                p = s.top();
                s.pop();
                if (pre != NULL) {
                    if (pre->val > p->val) {
                        //Why? For the firstMistake, the correct value is swapped with some value greater than it
                        //So the violation happens when checking the node with its successor, and then pre is the firstMistake node
                        //For the second mistake, its value has been swapped to be smaller, so the secondMistake node is p, not pre
                        if (!firstMistake) {
                            firstMistake = pre;
                            firstMistakeSuccessor = p;
                        } else {    //Assume there are at most 2 violations in the tree
                            secondMistake = p;
                        }
                    }
                }
                
                pre = p;
                p = p->right;
            }
        }
        
        if (!secondMistake) {
            swap(firstMistake, firstMistakeSuccessor);
        } else {
            swap(firstMistake, secondMistake);
        }
    }

private:
    void swap(TreeNode* p1, TreeNode* p2) {
        if (!p1 || !p2)
            return;
        
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }
};
