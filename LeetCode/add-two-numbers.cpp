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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        
        if (!l2)
            return l1;
        
        int carry = 0;
        int digit = 0;
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = dummyHead;
        
        while (p1 || p2) {
            int sum = carry;
            if (p1) {
                sum += p1->val;
                p1 = p1->next;
            }
            
            if (p2) {
                sum += p2->val;
                p2 = p2->next;
            }
            
            carry = sum / 10;
            digit = sum - carry * 10;
            
            ListNode* node = new ListNode(digit);
            
            p->next = node;
            p = node;
        }
        
        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            
            p->next = node;
            p = node;
        }
        
        p = dummyHead->next;
        
        delete dummyHead;
        
        return p;
    }
};
