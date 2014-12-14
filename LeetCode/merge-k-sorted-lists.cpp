//Min Heap: if a->val > b->val, then a < b
struct cmp {
    bool operator() (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> queue;
        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL)
                queue.push(lists[i]);
        }
        
        ListNode *dummyHead = new ListNode(0), *p = dummyHead;
        ListNode *tmp;
        while (!queue.empty()) {
            tmp = queue.top();
            queue.pop();
            p->next = tmp;
            p = p->next;
            if (tmp->next) {
                queue.push(tmp->next);
            }
        }
        
        ListNode *head = dummyHead->next;
        delete dummyHead;
        
        return head;
    }
};
