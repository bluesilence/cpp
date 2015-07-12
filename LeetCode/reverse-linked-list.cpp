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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* post = NULL;
        
        while (curr) {
            post = curr->next;
            curr->next = pre;
            pre = curr;
            curr = post;
        }
        
        return pre;
    }
};
