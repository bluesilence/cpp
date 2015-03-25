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
    ListNode *rotateRight(ListNode *head, int k) {
        //Split the list at the (len - k)th node into list a and b, then stitch b before a
        if (!head)
            return NULL;
        
        int len = getLen(head);
        
        //Avoid duplicate moves
        k = k % len;
        
        if (k == 0)
            return head;
            
        ListNode *aTail = head;
        for (int i = 1; i < len - k; k++) {
            aTail = aTail->next;
        }
        
        ListNode *bHead = aTail->next;
        aTail->next = NULL; //Cut off list a and b
        
        ListNode *bTail = bHead;
        while (bTail->next) {
            bTail = bTail->next;
        }
        
        bTail->next = head; //Stitch b before a
        
        return bHead;
    }

private:
    int getLen(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while (p) {
            len++;
            p = p->next;
        }
        
        return len;
    }
};
