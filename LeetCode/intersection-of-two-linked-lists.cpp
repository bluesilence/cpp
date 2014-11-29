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
        
        ListNode *pA = headA, *pB = headB;
        int lenA = getLen(headA), lenB = getLen(headB);
        
        //Move the pointers to the same starting line
        if (lenA < lenB) {
            for (int i = lenA; i < lenB; i++) {
                pB = pB->next;
            }
        } else if (lenB < lenA) {
            for (int i = lenB; i < lenA; i++) {
                pA = pA->next;
            }
        }
        
        while (pA && pB && pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        
        if (pA == pB)
            return pA;
        else
            return NULL;
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
