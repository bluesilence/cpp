/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        
        TreeNode *root = new TreeNode(0);
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        transform(dummyHead, root);
        
        return root;
    }

private:
    void transform(ListNode *preHead, TreeNode *root) {
        //To split left list, we need the pointer before mid
        ListNode *preMid = findPreMid(preHead);
        ListNode *mid = preMid->next;
        
        root->val = mid->val;
        
        if (mid->next) {
            root->right = new TreeNode(0);
            transform(mid, root->right);    //mid is the preHead of right list
        }
        
        if (preHead != preMid) {
            root->left = new TreeNode(0);
            preMid->next = NULL;    //Split left list
            transform(preHead, root->left);
        }
    }
    
    ListNode *findPreMid(ListNode *preHead) {
        if (!preHead)
            return NULL;
        
        ListNode *pSlow, *pFast;
        pSlow = pFast = preHead;
        
        while (pFast && pFast->next && pFast->next->next) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        
        return pSlow;
    }
};
