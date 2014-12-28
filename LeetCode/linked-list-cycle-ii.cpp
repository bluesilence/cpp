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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return NULL;
        
        //First, find a node in the circle with a fast pointer and a slow pointer
        //Second, suppose the fast pointer has walked 2*k steps, the slow pointer k steps
        //Suppose slow walked (a + b) steps, a steps before the circle, b steps in the circle
        //Fast walked (a + b + c + b) steps to meet slow, c steps in the circle
        //Then c + b == k == a + b, thus c == a
        //In other words, when walking from the met node, and walking from the head at the same speed, the 2 pointers will meet at the beginning of the circle
        ListNode *slow, *fast;
        slow = fast = head;
        do {
            slow = slow->next;
            fast = fast->next;
            if (fast->next)
                fast = fast->next;
            else
                return NULL;
        } while (slow != fast && fast->next);
        
        if (slow != fast)   //No cycle
            return NULL;
        
        ListNode *slow2 = head;
        while (slow2 != slow) {
            slow2 = slow2->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
