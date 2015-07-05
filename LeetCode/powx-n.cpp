class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        
        if (n == 0)
            return 1;
            
        double result = 0;
        
        if (n > 0)
            result = powCore(x, n);
        else
            result = 1 / powCore(x, 0 - (long long)n);
        
        return result;
    }

private:
    double powCore(double x, long long n) {
        if (x == 0)
            return 0;
        else if (n == 0)
            return 1;
            
        double half = powCore(x, n >> 1);
        
        if (n & 0x01) {
            return half * half * x;
        } else {
            return half * half;
        }
    }
};
