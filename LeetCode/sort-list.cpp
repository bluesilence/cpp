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
    ListNode *sortList(ListNode *head) {
        if(NULL == head || NULL == head->next)
            return head;
            
        ListNode *mid = getMiddleNode(head);
        ListNode *right = mid->next;
        mid->next = NULL; //Break 1 list into 2
        
        //recursively call
        return mergeSort(sortList(head), sortList(right));
    }

private:
    ListNode *getMiddleNode(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while(NULL != fast && NULL != fast->next && NULL != fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    ListNode *mergeSort(ListNode *left, ListNode *right) {
        ListNode *head = new ListNode(-1); //Dummy head
        ListNode *cur = head;
        
        while(NULL != left && NULL != right) {
            if(left->val < right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            
            cur = cur->next;
        }
        
        cur->next = NULL != left ? left : right;
        
        return head->next;
    }
};