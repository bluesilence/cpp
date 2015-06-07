class Solution {
public:
    int firstMissingPositive(vector<int> &A) {
        if (A.empty())
            return 1;
        
        int max = getMax(A);
        int *positiveNumbers = new int[max + 1];
        memset(positiveNumbers, 0, sizeof(int) * (max + 1));
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > 0) {
                positiveNumbers[A[i]] = A[i];
            }
        }
        
        for (int i = 1; i <= max; i++) {
            if (positiveNumbers[i] != i) {
                return i;
            }
        }
        
        delete positiveNumbers;
        
        return max + 1; //All positive numbers in A are continous. The missing integer is the next positive numbers of max
    }
    
private:
    int getMax(vector<int> &A) {
        int max = A[0];
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > max) {
                max = A[i];
            }
        }
        
        return max;
    }
};
