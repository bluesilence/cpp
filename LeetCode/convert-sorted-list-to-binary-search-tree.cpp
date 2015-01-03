/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head)
            return NULL;
        if (!head->next)
            return new TreeNode(head->val);
        
        //Find the middle node as root of tree
        ListNode *pre, *slow, *fast;
        pre = slow = fast = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //Cut list from slow
        ListNode *right = slow->next;
        ListNode *left = head;
        pre->next = NULL;
        
        //Connect left and right subtree root to current root
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(left);
        root->right = sortedListToBST(right);
        
        return root;
    }
};
