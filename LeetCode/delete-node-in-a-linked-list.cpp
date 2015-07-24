/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node)
            return;
        
        ListNode* post = node->next;
        node->val = post->val;
        node->next = post->next;
        
        delete post;
    }
};