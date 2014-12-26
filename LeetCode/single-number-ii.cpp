class Solution {
public:
    int singleNumber(int A[], int n) {
        return singleNumberCore(A, n, 3);
    }
    
private:
    int singleNumberCore(const int A[], const int n, const int k) {
        if (!A)
            return 0;
        
        if (n < k)
            return A[0];
        
        int bits[32] = { 0 };
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                bits[i] += (A[j] >> i) & 1;
            }
            
            result |= (bits[i] % k) << i;
        }
        
        return result;
    }
};
