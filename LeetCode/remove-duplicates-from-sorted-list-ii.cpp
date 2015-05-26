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
        
        ListNode *dummyHead = new ListNode(0);
        
        dummyHead->next = head;
        
        ListNode *pFast, *pSlow;
        pFast = head;
        pSlow = dummyHead;
        
        while (pFast) {
            while (pFast->next && pSlow->next->val == pFast->next->val) {
                pFast = pFast->next;
            }
            
            if (pSlow->next == pFast) {  //pFast->val is distinct
                pSlow = pSlow->next;
            } else {    //Skip pFast->val since there are duplicates, but we don't know if next number has duplicates, so pSlow stay unchanged here, just change pSlow->next.
                pSlow->next = pFast->next;
            }
            
            pFast = pFast->next;
        }
        
        head = dummyHead->next;
        
        delete dummyHead;
        
        return head;
    }
};
