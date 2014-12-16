class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        //Initial carry = 0
        //Scan the lists node by node
        //Add values of each pair of nodes with previous carry
        //Update the carry if the sum > 9
        if (!l1)
            return l2;
        
        if (!l2)
            return l1;
        
		ListNode *dummyHead = new ListNode(0), *p = dummyHead;
        int carry = 0;
        int sum = 0;
        while (l1 && l2) {
            sum = l1->val + l2->val + carry;
            if (sum > 9) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            
            ListNode *node = new ListNode(sum);
            //Tail insertion
            p->next = node;
            p = node;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        //Attach the remainder
        while (l1) {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
            if (carry > 0) {
                p->val++;
                //Take care of the carry here
                if (p->val > 9) {
					p->val -= 10;
					carry = 1;
				} else {
					carry = 0;
				}
            }
        }
        
        //Attach the remainder
        while (l2) {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
            if (carry > 0) {
                p->val++;
                //Take care of the carry here
				if (p->val > 9) {
					p->val -= 10;
					carry = 1;
				} else {
					carry = 0;
				}
            }
        }
        
        if (carry > 0) {    //Create new node for the carry on most significant digit
            p->next = new ListNode(carry);
            carry = 0;
        }
        
        p = dummyHead->next;
        delete dummyHead;
        
        return p;
    }
};
