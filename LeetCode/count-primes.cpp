class Solution {
public:
    int countPrimes(int n) {
        if (n - 1 <= 1)
            return 0;
            
        vector<bool> isPrime(n, true);
        
        int primeCount = 0;
        int upperBound = sqrt(n);
        
        for (int i = 2; i < n; i++) {  //Start from 2 since 1 * j == j, all the following numbers will be affected
            if (isPrime[i-1]) {
                primeCount++;
                
                //When i > upper, i(bigger) * j(smaller) has already been checked, where i(bigger) == j(old) and i(smaller) == j(new)
                //Eg. n == 11, 2 * 5 == 10 has been checked when i == 2 and j == 5, so when i == 5 > 3, no need to check 5 * 2 where i == 5 and j == 2.
                if (i > upperBound)
                    continue;
                    
                for (int j = i; i * j < n; j++) {   //j >= i, so that i(bigger) * j(smaller) has already been checked in previous loops
                    isPrime[i*j - 1] = false;
                }
            }
        }
        
        return primeCount;
    }
};
