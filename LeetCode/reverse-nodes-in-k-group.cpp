class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2 || !head || !head->next)  //No need to reverse
            return head;
            
        //Use 2 pointers, 1 points to the begin of a k-node group, 1 points to the end
        ListNode *begin, *end;
        ListNode *pre, *post;
		    ListNode *dummyHead = new ListNode(0);
        
        begin = end = head;
        pre = dummyHead;
        pre->next = head;
        
        bool hasGroup = true;
        while (begin && hasGroup) {
            for (int i = 1; i < k; i++) {
                if (end && end->next) {
                    end = end->next;
                } else {
                    //If there is no more valid group, break the loop and return head
                    hasGroup = false;
                    break;
                }
            }
            
            if (hasGroup) {
                if (begin == head) {    //First group
                    head = end;
                }
                
                post = end->next;
                
                //Reverse the sub list of k nodes and stitch it back to the main list
                reverse(begin, end, pre, post);
                
                //Move the pointers to the next group
                pre = begin;
                end = post;
                begin = end;
            }
        }
        
        delete dummyHead;
        
        return head;
    }
    
private:
    void reverse(ListNode *begin, ListNode *end, ListNode *pre, ListNode *post) {
        if (begin == end || !begin || !end)
            return;
        
        ListNode *p = begin;
        stack<ListNode*> s;
        while (p && p != end) {
            s.push(p);
            p = p->next;
        }
        
        p = end;
        while (!s.empty()) {
            p->next = s.top();
            s.pop();
            p = p->next;
        }
        
        //Stitch the reversed sub list back into the main list
        pre->next = end;
        begin->next = post;
    }
};
