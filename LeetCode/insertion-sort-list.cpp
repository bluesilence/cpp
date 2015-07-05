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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode *unordered = head->next;
        head->next = NULL;  //Split ordered and unordered parts
        
        while (unordered) {    //There is still unordered node
            ListNode *tmp = dummyHead;
            
            while (tmp->next && tmp->next->val <= unordered->val) {
                tmp = tmp->next;
            }
            
            ListNode *nextUnordered = unordered->next;
            unordered->next = tmp->next;
            tmp->next = unordered;
            unordered = nextUnordered;
        }
        
        head = dummyHead->next;
        
        delete dummyHead;
        
        return head;
    }
};
