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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k < 2)
            return head;
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* slow = dummyHead;
        ListNode* fast = head;
        
        while (fast) {
            int i = 1;
            while (i < k) {
                if (fast->next) {
                    fast = fast->next;
                    i++;
                } else {
                    break;
                }
            }
            
            if (i == k) {
                //After reverse, slow->next is the tail of this k group
                ListNode* groupEnd = slow->next;
                reverse(slow, fast);
                //After reverse, fast is the head of the list
                slow = groupEnd;
                fast = groupEnd->next;
            } else {    //No k nodes to reverse
                break;
            }
        }
        
        head = dummyHead->next;
        
        delete dummyHead;
        
        return head;
    }

private:
    void reverse(ListNode* preBegin, ListNode* end) {
        ListNode* pre = end->next;
        ListNode* p = preBegin->next;
        ListNode* post = NULL;
        ListNode* postEnd = end->next;
        
        while (p && p != postEnd) {
            post = p->next;
            p->next = pre;
            pre = p;
            p = post;
        }
        
        preBegin->next = pre;   //Stitch back to prior list
    }
};
