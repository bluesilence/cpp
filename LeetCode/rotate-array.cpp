class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (n < 2 || k % n == 0)
            return;
            
        int *numsDup = new int[n * 2];
        for (int i = 0; i < 2*n; i++) {
            numsDup[i] = nums[i%n];
        }
        
        k = k % n;
        int offset = n - k;
        for (int i = 0; i < n; i++) {
            nums[i] = numsDup[i + offset];
        }
        
        delete numsDup;
    }
};
