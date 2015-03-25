class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int k = lists.size();
        if (k == 0)
            return NULL;
        
        int step;
        
        //Divide-and-Conquer -- Time complexity: O(nklogk), where n is the average length of all the lists
        while (k > 1) {
            step = (k + 1) / 2;
            for (int i = 0; i < k/2; i++) {
                lists[i] = merge2Lists(lists[i], lists[i + step]);
            }
            
            k = step;
        }
        
        return lists[0];
    }

private:
    ListNode *merge2Lists(ListNode *list1, ListNode *list2) {
        if (!list1)
            return list2;
        
        if (!list2)
            return list1;
        
        ListNode *dummyHead = new ListNode(0);
        ListNode *p = dummyHead;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            
            p = p->next;
        }
        
        if (list1)
            p->next = list1;
        else if (list2)
            p->next = list2;
        
        p = dummyHead->next;
        delete dummyHead;
        
        return p;
    }
};
