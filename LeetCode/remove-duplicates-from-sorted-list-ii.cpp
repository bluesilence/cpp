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
    ListNode *deleteDuplicates(ListNode *head) {
        //Use 2 pointers, 1 points to the first distinct node, 1 moves forward until the next node is not duplicate
        if (!head || !(head->next))
            return head;
            
        ListNode *dummyHead, *pre, *cur;
        dummyHead = new ListNode(0);    //Dummy head
        pre = dummyHead;
        dummyHead->next = head;
        cur = head;
        while (cur) {
            while (cur->next && pre->next->val == cur->next->val)
                cur = cur->next;
            
            //No duplicates
            if (pre->next == cur) {
                pre = pre->next;
            } else {
                pre->next = cur->next;
            }
            
            cur = cur->next;
        }
        
        pre = dummyHead->next;
        delete dummyHead;
        
        return pre;
    }
};
