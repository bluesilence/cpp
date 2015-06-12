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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m >= n)
            return head;
        
        ListNode *dummyHead = new ListNode(0);
        
        dummyHead->next = head;
        
        ListNode *preStart = dummyHead;
        
        int i = 1;
        
        while (preStart && preStart->next && i < m) {
            preStart = preStart->next;
            
            i++;
        }
        
        ListNode *pre = NULL;
        ListNode *p = preStart->next;
        ListNode *post = NULL;
        
        while (p && i <= n) {
            post = p->next;
            p->next = pre;
            pre = p;
            p = post;
            
            i++;
        }
        
        //Original head is the tail of reversed list
        ListNode *tail = preStart->next;
        
        //pre is the head of reversed list
        preStart->next = pre;
        tail->next = p;
        
        head = dummyHead->next;
        delete dummyHead;
        
        return head;
    }
};
