class Solution {
public:
    double pow(double x, int n) {
        if (0 == x)
            return 0;
        
        if (n == 0)
            return 1;
        else if (n < 0)
            return 1 / powCore(x, 0 - n);
        else
            return powCore(x, n);
    }

private:
    double powCore(double x, int n) {
        if (0 == n)
            return 1;
            
        double half = powCore(x, n/2);
        
        if (0 == (n & 0x01)) {    //n is even
            return half * half;
        } else {
            return x * half * half;
        }
    }
};
