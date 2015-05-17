class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return numeric_limits<int>::max();
        
        //Note: MIN_INT may overflow when converted to absolute value
        long long absDividend = dividend > 0 ? dividend : (0 - (long long)dividend);
        long long absDivisor = divisor > 0 ? divisor : (0 - (long long)divisor);
        long long absResult = dividePositive(absDividend, absDivisor);
        long long result;
        
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) {
            result = -1 * absResult;
        } else {
            result = absResult;
        }
        
        if (result > numeric_limits<int>::max())
            return numeric_limits<int>::max();
        //else if (result < numeric_limits<int>::min())  //Impossible, since MIN_INT / 1 == MIN_INT, it can't be smaller
        //    return numeric_limits<int>::min();
        else
            return (int)result;
    }
    
private:
    long long dividePositive(long long dividend, long long divisor) {
        long long result = 0;
        while (dividend >= divisor) {
            long long sum = divisor;
            long long count = 1;
            while (dividend >= (sum << 1)) {
                sum <<= 1;
                count <<= 1;
            }
            
            result += count;
            dividend -= sum;
        }
        
        return result;
    }
};
