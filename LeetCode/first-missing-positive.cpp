class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (!A || n <= 0)
            return 1;
        
        int max = getMax(A, n);
        
        //Put each positive integer i at subscript i of the array
        vector<int> positions(max+1, -1);
        for (int i = 0; i < n; i++) {
            if (A[i] > 0)
                positions[A[i]] = A[i];
        }
        
        for (int i = 1; i <= max; i++) {
            if (positions[i] != i)
                return i;
        }
        
        return max+1;
    }

private:
    int getMax(int A[], int n) {
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > max)
                max = A[i];
        }
        
        return max;
    }
};
