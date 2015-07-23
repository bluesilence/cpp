class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {   //No prime number that is less than 2
            return 0;
        }
        
        int count = 0;
        int upperBound = sqrt(n);
        
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        
        for (int i = 2; i < n; i++) {
            if (isPrime[i-1]) {
                count++;
            }
            
            if (i > upperBound)
                continue;
                
            for (int j = i; i * j <= n; j++) {
                isPrime[i*j - 1] = false;
            }
        }
        
        return count;
    }
};
