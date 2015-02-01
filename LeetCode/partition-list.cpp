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
    ListNode *partition(ListNode *head, int x) {
        if(!head || !head->next)
            return head;

        ListNode *smallerHead = new ListNode(0), *smallerTail = smallerHead;
        ListNode *biggerHead = new ListNode(0), *biggerTail = biggerHead;
        ListNode *cur = head;

        while(cur) {
            if(cur->val < x) {
                smallerTail -> next = cur;
                cur = cur -> next;
                smallerTail = smallerTail -> next;
                smallerTail -> next = NULL;
            }else{
                biggerTail -> next = cur;
                cur = cur -> next;
                biggerTail = biggerTail -> next;
                biggerTail -> next = NULL;
            }
        }
        
        smallerTail->next = biggerHead->next;
        head = smallerHead->next;
        
        delete smallerHead;
        delete biggerHead;
        
        return head;
    }
};
