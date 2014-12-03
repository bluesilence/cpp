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
        //Ask the interviewer if we need to delete the removed pointers on the list
        //Use 2 pointers, slow and fast
        //Loop until slow == NULL
        //When slow meets a new node, it stays, and let fast move forward until it reaches a non-dup node
        //If there is any dup node, modify slow->next <= fast->next, fast <= fast->next, slow <= fast
        if (!head || !head->next)
            return head;
            
        ListNode *slow, *fast;
        slow = fast = head;
        
        while (fast && fast->next) {
            int target = slow->val;
            while (fast && fast->next && fast->next->val == target) {
                fast = fast->next;
            }
            
            if (fast && slow != fast) {
                fast = fast->next;
                slow->next = fast;
                slow = fast;
            } else {    //No dup nodes, move both pointers forward
                slow = slow->next;
                fast = slow;
            }
        }
        
        return head;
    }
};
