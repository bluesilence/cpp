class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (!B || n < 1)
            return;
            
        int indexA = 0, indexB = 0;
        int *tmp = new int[m + n];
        int i = 0;
        for (; i < m + n; i++) {
            if (indexA >= m || indexB >= n)
                break;
                
            if (A[indexA] < B[indexB]) {
                tmp[i] = A[indexA++];
            } else {
                tmp[i] = B[indexB++];
            }
        }
        
        while (indexA < m) {
            tmp[i++] = A[indexA++];
        }
        
        while (indexB < n) {
            tmp[i++] = B[indexB++];
        }
        
        for (i = 0; i < m + n; i++) {
            A[i] = tmp[i];
        }
        
        delete tmp;
    }
};
