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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || !head->next)
            return head;
            
        ListNode *preBegin = NULL;
        ListNode *begin = head;
        //Move preBegin to the node before the head of the sub list to be reversed
        for(int i = 1; i < m; i++)
        {
            preBegin = begin;
            begin = begin->next;
        }
        
        //The end of reversed sub list
        ListNode *end = begin;
        //pre and post are 2 pointers used for traverse the sub list and reverse one by one
        ListNode *pre = begin;
        ListNode *post = NULL;
        begin = begin->next;
        
        for(int i = m; i < n; i++)
        {
            post = begin->next;
            begin->next = pre;
            pre = begin;
            begin = post;
        }
        
        //begin now points to the node after the reversed sub list
        end->next = begin;
        
        //pre now points to the head of the reversed sub list
        if (preBegin)
            preBegin->next = pre;
        else
            head = pre;
        
        return head;
    }
};
