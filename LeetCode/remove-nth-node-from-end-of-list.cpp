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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head)
            return NULL;
        
        if (!head->next && n == 1)
            return NULL;
            
        ListNode *p = head, *q = head, *pre = p;
        
        while (q && q->next && n > 1) {
            q = q->next;
            n--;
        }
        
        //The nth node from the end doesn't exist
        if (n > 1) {
            return head;
        } else {
            //Locate the nth node from the end
            while (q->next) {
                q = q->next;
                pre = p;
                p = p->next;
            }
        }
        
        if (p == q) {   //n == 1
            pre->next = q->next;
            if (head == p) {
                head = p->next;
            }
            
            delete p;
        } else {
            //Delete p by copying the value of p->next
            ListNode *tmp = p->next;
            p->val = tmp->val;
            p->next = tmp->next;
            
            delete tmp;
        }
        
        return head;
    }
};
