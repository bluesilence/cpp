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
    ListNode* sortList(ListNode* head) {
        //O(nlogn) time complexity implies MergeSort
        if (!head || !head->next)
            return head;
        
        ListNode *mid = getMiddleNode(head);
        ListNode *right = mid->next;
        mid->next = NULL;
        
        return mergeSort(sortList(head), sortList(right));
    }

private:
    ListNode *getMiddleNode(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode *mergeSort(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
            
        if (!l2)
            return l1;
        
        ListNode *dummyHead = new ListNode(0);
        ListNode *p = dummyHead;
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            
            p = p->next;
        }
        
        if (p1) {
            p->next = p1;
        }
        
        if (p2) {
            p->next = p2;
        }
        
        p = dummyHead->next;
        
        delete dummyHead;
        
        return p;
    }
};
