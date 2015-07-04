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
        //Use a map to store the mapping between original node and copied node
        unordered_map<RandomListNode*, RandomListNode*> mappings;
        
        RandomListNode *dummyHead = new RandomListNode(0);
        RandomListNode *pCopy = dummyHead;
        
        RandomListNode *pOrigin = head;
        
        while (pOrigin) {
            RandomListNode *newNode = new RandomListNode(pOrigin->label);
            pCopy->next = newNode;
            
            mappings[pOrigin] = newNode;
            
            pOrigin = pOrigin->next;
            pCopy = pCopy->next;
        }
        
        pOrigin = head;
        pCopy = dummyHead->next;
        
        while (pOrigin) {
            pCopy->random = mappings[pOrigin->random];
            
            pOrigin = pOrigin->next;
            pCopy = pCopy->next;
        }
        
        pCopy = dummyHead->next;
        
        delete dummyHead;
        
        return pCopy;
    }
};
