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
        
        ListNode* p = head;
        
        //Use a stack to store the first half
        stack<ListNode*> s;
        
        //Count the number of nodes
        int len = getLen(head);
        int half = len / 2;
        for (int i = 0; i < half; i++) {
            s.push(p);
            p = p->next;
        }
        
        //If the number is odd, skip the node (center) after the slow pointer before starting comparison
        if (len & 0x01 == 1) {
            p = p->next;
        }
        
        //Scan the second half, and compare with the top of the stack
        //If not match, return false
        while (p && !s.empty()) {
            if (p->val != s.top()->val) {
                return false;
            }
            
            s.pop();
            p = p->next;
        }
        
        //If all the nodes in the stack are matched, return true
        return !p && s.empty();
    }

private:
    int getLen(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        
        return len;
    }
};
