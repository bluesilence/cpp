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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *dummyHead = new ListNode(0);
        
        dummyHead->next = head;
        ListNode *pre, *p, *post;
        pre = dummyHead;
        p = head;
        
        while (p) {
            post = p->next;
            p->next = pre;
            pre = p;
            p = post;
        }
        
        head->next = NULL;
        delete dummyHead;
        
        return pre;
    }
};
