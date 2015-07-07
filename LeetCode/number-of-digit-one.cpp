class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;
        
        long long count = 0;    //It may cause integer overflow
        
        long long factor = 1;
        
        while (n / factor) {
            int lowerNum = n - (n / factor) * factor;
            int currentDigit = (n / factor) % 10;
            int higherDigit = n / (factor * 10);
            
            switch(currentDigit) {
                case 0:
                    count += higherDigit * factor;
                    break;
                case 1:
                    count += higherDigit * factor + (lowerNum + 1);
                    break;
                default:
                    count += (higherDigit + 1) * factor;
            }
            
            factor *= 10;
        }
        
        return count;
    }
};
