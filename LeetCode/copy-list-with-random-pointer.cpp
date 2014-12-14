/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
            
        map<RandomListNode*, RandomListNode*> mappings;
        
        //First copy the next nodes
        RandomListNode *p = head;
        RandomListNode *copyHead = new RandomListNode(head->label);
        RandomListNode *q = copyHead;
        
        while (p) {
            if (p->next)
                q->next = new RandomListNode(p->next->label);
                
            q->random = p->random;
            mappings[p] = q;
            
            p = p->next;
            q = q->next;
        }
        
        //Next copy the random nodes
        p = head;
        q = copyHead;
        while (q) {
            q->random = mappings[q->random];
            q = q->next;
        }
        
        return copyHead;
    }
};
