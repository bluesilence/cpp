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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *pSlow = head;
        ListNode *pFast = head->next;
        
        while (pFast) {
            while (pFast && pFast->val == pSlow->val) {
                pFast = pFast->next;
            }
            
            pSlow->next = pFast;
            pSlow = pSlow->next;
            
            if (pFast) {
                pFast = pFast->next;
            }
        }
        
        return head;
    }
};
