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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode *pre = dummyHead;
        ListNode *p = head;
        ListNode *q;
        while (p && p->next) {
            q = p->next;
            //Swap p and q
            p->next = q->next;
            pre->next = q;
            q->next = p;
            //Adjust link to head node
            if (head == p)
                head = q;
            pre = p;
            p = pre->next;
        }
        
        delete dummyHead;
        
        return head;
    }
};
