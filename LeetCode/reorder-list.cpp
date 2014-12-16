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
    void reorderList(ListNode *head) {
        if (!head || !head->next)
            return;
        
        //Split the list into 2 parts
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *firstHalf = head, *secondHalf = slow->next;
        slow->next = NULL;
        
        //For the 2nd half, reorder it using head insertion
        ListNode *pre, *p, *tmp;
        pre = secondHalf;
        p = pre->next;
        pre->next = NULL;
        
        while (p) {
            tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        
        secondHalf = pre;
        
        //Link the 2 lists together
        ListNode *fp, *sp;
        ListNode *fTmp, *sTmp;
        fp = firstHalf;
        sp = secondHalf;
        while (fp && sp) {
            fTmp = fp->next;
            sTmp = sp->next;
            fp->next = sp;
            sp->next = fTmp;
            fp = fTmp;
            sp = sTmp;
        }
    }
};
