class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        
        int primeCount = 0;
        
        for (int i = 2; i < n; i++) {  //Start from 2 since 1 * j == j, all the following numbers will be affected
            if (isPrime[i-1]) {
                primeCount++;
                
                for (int j = 2; i * j < n; j++) {
                    isPrime[i * j - 1] = false;
                }
            }
        }
        
        return primeCount;
    }
};
