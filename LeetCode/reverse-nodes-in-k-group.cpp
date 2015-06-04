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
        //Cut list into k-group
        //Reverse each sublist recursively
        //Stitch sublist back
        if (k < 2)
            return head;
        
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode *p = dummyHead;
        ListNode *q;
        ListNode *begin;
        ListNode *end;
        
        while (p && p->next && p->next->next) {
            begin = p->next;
            end = begin;
            
            for (int i = 1; i < k; i++) {
                if (end && end->next) {
                    end = end->next;
                } else {
                    break;
                }
            }
            
            q = end->next;
            end->next = NULL;   //Cut the k nodes off the list
            
            int len = getLen(begin);
            if (k > len) {  //Not enough nodes, do not reverse
                break;
            }
            
            reverseList(&begin, &end);
            
            p->next = begin;
            end->next = q;
            p = end;    //pre to next k-group
        }
        
        head = dummyHead->next;
        
        delete dummyHead;
        
        return head;
    }

    void reverseList(ListNode **begin, ListNode **end) {
        ListNode *head = *begin;
        ListNode *tail = *end;
        
        if (head == tail)
            return;
        
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode *pre = dummyHead;
        ListNode *cur = head;
        ListNode *next;
        
        while (cur && cur->next) {
            next = cur->next;
            
            cur->next = pre;
            
            pre = cur;
            cur = next;
        }
        
        cur->next = pre;    //Last node
        
        *end = *begin;
        (*end)->next = NULL;
        
        *begin = cur;
        
        delete dummyHead;
    }

private:
    int getLen(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while (p) {
            len++;
            p = p->next;
        }
        
        return len;
    }
};
