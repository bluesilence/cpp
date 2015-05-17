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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || (!head->next && n > 0))
            return NULL;
            
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode *slow = dummyHead;
        ListNode *fast = slow;
        
        while (n > 0 && fast && fast->next) {
            fast = fast->next;
            n--;
        }
        
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode *tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        
        head = dummyHead->next;
        delete dummyHead;
        
        return head;
    }
};
