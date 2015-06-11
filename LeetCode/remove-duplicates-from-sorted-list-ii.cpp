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
        
        ListNode *p = dummyHead;
        ListNode *q = head;
        
        bool hasDup;
        while (q && q->next) {
            hasDup = false;
            
            while (q && q->next && q->val == q->next->val) {
                q = q->next;
                hasDup = true;
            }
            
            if (!hasDup) {
                p->next = q;
                p = q;
            } else {    //We don't yet know if the next nodes have duplicates, so keep p unchanged here
                p->next = q->next;
            }
            
            q = q->next;
        }
        
        head = dummyHead->next;
        
        delete dummyHead;
        
        return head;
    }
};
