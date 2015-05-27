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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)
            return head;
        
        ListNode *dummyHeadLeft = new ListNode(0);
        ListNode *dummyHeadRight = new ListNode(0);
        
        ListNode *p = head;
        ListNode *pLeft = dummyHeadLeft, *pRight = dummyHeadRight;
        ListNode *pNext = NULL;
        
        while (p) {
            pNext = p->next;
            if (p->val < x) {
                pLeft->next = p;
                pLeft = p;
                pLeft->next = NULL; //To avoid circular list between pLeft and pRight
            } else {
                pRight->next = p;
                pRight = p;
                pRight->next = NULL; //Same as above
            }
            
            p = pNext;
        }
        
        pLeft->next = dummyHeadRight->next;
        
        head = dummyHeadLeft->next;
        
        delete dummyHeadLeft;
        delete dummyHeadRight;
        
        return head;
    }
};
