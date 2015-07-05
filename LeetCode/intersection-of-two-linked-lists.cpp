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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        
        if (lenA < lenB) {
            for (int i = lenA; i < lenB; i++) {
                headB = headB->next;
            }
        } else if (lenA > lenB) {
            for (int i = lenB; i < lenA; i++) {
                headA = headA->next;
            }
        }
        
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return (headA == headB) ? headA : NULL;
    }

private:
    int getLen(ListNode *head) {
        int len = 0;
        
        while (head) {
            len++;
            head = head->next;
        }
        
        return len;
    }
};
