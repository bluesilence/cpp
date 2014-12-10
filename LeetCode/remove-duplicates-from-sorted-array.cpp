class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (!A || n < 2)
            return n;
        
        int fast = 1, slow = 0;
        
        while (fast < n) {
            if (A[slow] == A[fast])
                fast++;
            else
                A[++slow] = A[fast++];
        }
        
        return slow + 1;
    }
};
