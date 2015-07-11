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
    bool isPalindrome(ListNode* head) {
        //The list is palindrome == center-symmetric
        if (!head || !head->next)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        //Locate the center of the list
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //Reverse list after slow
        reverseList(slow);
        
        ListNode* secondHalf = slow->next;
        ListNode* firstHalf = head;
        while (secondHalf) {
            if (secondHalf->val != firstHalf->val) {
                //Restore original list
                reverseList(slow);
                
                return false;
            }
            
            secondHalf = secondHalf->next;
            firstHalf = firstHalf->next;
        }
        
        //Restore original list
        reverseList(slow);
        
        return true;
    }

private:
    void reverseList(ListNode *preHead) {
        ListNode* curr = preHead->next;
        ListNode* pre = NULL;
        ListNode* post = NULL;
        
        while (curr) {
            post = curr->next;
            curr->next = pre;
            pre = curr;
            curr = post;
        }
        
        preHead->next = pre;
    }
};
