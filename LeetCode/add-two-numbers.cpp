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
        ListNode *dummyHead = new ListNode(0);
        ListNode *p = dummyHead;
        
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            if (sum >= 10) {
                carry = sum / 10;
                sum %= 10;
            } else {
                carry = 0;
            }
            
            ListNode *node = new ListNode(sum);
            p->next = node;
            p = node;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            int sum = l1->val + carry;
            if (sum >= 10) {
                carry = sum / 10;
                sum %= 10;
            } else {
                carry = 0;
            }
            
            ListNode *node = new ListNode(sum);
            p->next = node;
            p = node;
            l1 = l1->next;
        }
        
        while (l2) {
            int sum = l2->val + carry;
            if (sum >= 10) {
                carry = sum / 10;
                sum %= 10;
            } else {
                carry = 0;
            }
            
            ListNode *node = new ListNode(sum);
            p->next = node;
            p = node;
            l2 = l2->next;
        }
        
        if (carry > 0) {
            ListNode *node = new ListNode(carry);
            p->next = node;
        }
        
        ListNode *head = dummyHead->next;
        delete dummyHead;
        
        return head;
    }
};
