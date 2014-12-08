class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (!A || n < 1)
            return 0;
            
        int fast = 0, slow = 0;
        
        //Find the first occurrence of elem
        while (slow < n && A[slow] != elem) {
            slow++;
        }
        
        if (slow < n) {
            fast = slow;
        } else {
            return n;
        }

        //Copy non-elem numbers onto elems
        while (fast < n) {
            while (fast < n && A[fast] == elem) {
                fast++;
            }
        
            while (fast < n && A[fast] != elem) {
                A[slow++] = A[fast++];
            }
        }
        
        return slow;
    }
};
