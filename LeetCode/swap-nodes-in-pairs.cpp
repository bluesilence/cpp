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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode *p = dummyHead;
        ListNode *p1, *p2;
        ListNode *tmp;
        while (p && p->next && p->next->next) {
            p1 = p->next;
            p2 = p1->next;
            tmp = p2->next;
            p->next = p2;
            p2->next = p1;
            p1->next = tmp;
            
            p = p1;
        }
        
        head = dummyHead->next;
        delete dummyHead;
        
        return head;
    }
};
