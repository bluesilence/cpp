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
        //Split the list into 2 sublists, and swap them
        if (!head || !head->next)
            return head;
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        k = k % getLen(head);
        
        //No rotation needed
        if (k == 0)
            return head;
            
        for (int i = 0; i < k; i++) {
            p2 = p2->next;
        }
        
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        ListNode *head1 = head;
        ListNode *head2 = p1->next;
        
        p1->next = NULL;
        p2->next = head1;
        
        return head2;
    }

private:
    int getLen(ListNode *head) {
        int len = 0;
        
        while (head) {
            head = head->next;
            len++;
        }
        
        return len;
    }
};
