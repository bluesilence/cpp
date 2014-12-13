class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (!A || n < 1)
            return 0;
        
        int globalMax = 0, tempMax = 0;
        for (int i = 0; i < n; i++) {
            tempMax += A[i];
            if (tempMax > globalMax)
                globalMax = tempMax;
            
            //Discard negative sums
            if (tempMax < 0)
                tempMax = 0;
        }
        
        if (globalMax <= 0)  {   //All elements are negative
            globalMax = A[0];
            for (int i = 1; i < n; i++) {
                if (A[i] > globalMax)
                    globalMax = A[i];
            }
        }
        
        return globalMax;
    }
};
