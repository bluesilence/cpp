class Solution {
public:
    int divide(int dividend, int divisor) {
        if (0 == divisor)
            return numeric_limits<int>::max();
        
        bool isNegative = false;
        long long result = 0;
		    //long is not enough, because it takes 4 bits as the same as int. It must be long long (8 bits) here
		    long long divid = dividend, divis = divisor;	//To prevent abs cause overflow

		    //Get absolute dividend and divisor
        if (dividend < 0) {
            isNegative = !isNegative;
            divid = 0 - divid;
        }
        
        if (divisor < 0) {
            isNegative = !isNegative;
            divis = 0 - divis;
        }
        
		    long long count = 0;
		    long long sum = 0;
        while (divid >= divis) {
          count = 1;                //a >= b ensures count >= 1
          sum = divis;
          while (sum<<1 <= divid) {
            sum <<= 1;
            count <<= 1;
          }

          divid -= sum;
          result += count;
        }
        
        result = isNegative ? -1 * result : result; //integer's MIN_VALUE / (-1) == 0 - MIN_VALUE > MAX_VALUE, overflow
        if (result > numeric_limits<int>::max() || result < numeric_limits<int>::min())
          return numeric_limits<int>::max();
        else
          return (int)result;
    }
};
