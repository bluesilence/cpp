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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return NULL;
            
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pFast, *pSlow;
        pFast = pSlow = dummy;
        
        while (pFast->next) {
            if (val == pFast->next->val) {
                pFast = pFast->next;
            } else {
                pSlow->next->val = pFast->next->val;
                pSlow = pSlow->next;
                pFast = pFast->next;
            }
        }
        
        pSlow->next = NULL;
        
        head = dummy->next;
        delete dummy;
        
        return head;
    }
};
