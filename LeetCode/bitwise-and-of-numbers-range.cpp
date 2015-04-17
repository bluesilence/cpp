class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
            
        int highestBit = getHighestBit(n);
        int mask = 1 << highestBit;
        
        //Find the lowest common bits of m and n from the highest bit of n. The AND result will be the same as the common bits
        //For the bits that are not the same, there are numbers between m and n that have flips on those bits, so the AND result must be 0 for them
        while (mask > 0) {
            int mBit = m & mask;
            int nBit = n & mask;
            if (mBit != nBit)
                break;
            else {
                result |= mBit;
                mask >>= 1;
            }
        }
        
        return result;
    }

private:
    int getHighestBit(int n) {
        int bit = 0;
        while (n >>= 1) {
            bit++;
        }
        
        return bit;
    }
};
