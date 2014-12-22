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
    ListNode *insertionSortList(ListNode *head) {
        if (!head)
            return NULL;
        
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        //The ordered sequence is originally only 1 node: head
        //Loop until the unordered part is NULL
        //For each node A in the unordered part, find the first node B that has value > A in the ordered part
        //If B is not null, insert A before B, else insert A at the tail of ordered part
        //Modify the unordered part to start from original A's next node
        ListNode *unOrdered = head->next;
        
        //To avoid circular list
        head->next = NULL;
        
        while (unOrdered) {
            //Scan the entire ordered part to locate where to insert the unOrdered node
			ListNode *tmpPre = dummyHead, *tmpOrdered = tmpPre->next;
            ListNode *nextUnOrdered = unOrdered->next;
            
            while (tmpOrdered && tmpOrdered->val < unOrdered->val) {
                tmpPre = tmpOrdered,
                tmpOrdered = tmpOrdered->next;
            }
            
            if (tmpOrdered != unOrdered) {  //Insert unOrdered between tmpPre and tmpOrdered
                unOrdered->next = tmpOrdered;
                tmpPre->next = unOrdered;
            } else {    //Node unOrdered is greater than any nodes in the ordered part, no need to insert
                unOrdered->next = NULL; //To avoid circular list
            }
            
            unOrdered = nextUnOrdered;
        }
        
        ListNode *newHead = dummyHead->next;
        delete dummyHead;
        
        return newHead;
    }
};
