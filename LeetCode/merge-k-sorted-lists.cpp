class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return NULL;
        
        int k = lists.size();
        int halfFloor, halfCeiling;
        
        //k is the length of lists that haven't been merged
        while (k > 1) {
            //halfCeiling is the step between 2 lists that can be merged
            halfCeiling = (k + 1) / 2;
            //halfFloor is the pair of lists that can be merged
            halfFloor = k / 2;
            for (int i = 0; i < halfFloor; i++) {
                lists[i] = merge2Lists(lists[i], lists[i+halfCeiling]);
            }
            
            //There might be 1 list left unmerged, so k is halfCeiling, not halfFloor
            k = halfCeiling;
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
