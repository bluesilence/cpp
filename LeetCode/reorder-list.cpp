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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        
        ListNode *slow;
        ListNode *fast;
        slow = fast = head;
        
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *right = slow->next;   //The right half
        slow->next = NULL;  //Split the left half
        
        reverseList(right);
        
        ListNode *p = head;
        ListNode *q = right;
        
        //Right half is always (0~1) node shorter than left half
        while (q) {
            ListNode *pTmp = p->next;
            ListNode *qTmp = q->next;
            
            p->next = q;
            q->next = pTmp;
            p = pTmp;
            q = qTmp;
        }
    }

private:
    void reverseList(ListNode* &head) {
        if (!head || !head->next)
            return;
        
        ListNode *pre = NULL;
        ListNode *curr = head;
        ListNode *post = NULL;
        
        while (curr) {
            post = curr->next;
            curr->next = pre;
            pre = curr;
            curr = post;
        }
        
        head = pre;
    }
};
