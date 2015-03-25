class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0)
            return false;
            
        int step = A[0];
        
        //Greedy strategy: Always maintain the max steps at each index
        for (int i = 1; i < n; i++) {
            if (step > 0) {
                step--;
                step = max(step, A[i]);
            }
            else {
                return false;
            }
        }
                
        return true;
    }
};
