class Solution {
public:
    int trailingZeroes(int n) {
        //Count how many 5s and 2s that are in the multiplication of n!
        //The zeros number = min(5s, 2s)
        int count2s = 0, count5s = 0;
        
        int num;
        for (int i = 1; i <= n; i++) {
            num = i;
            while (num % 2 == 0) {
                count2s ++;
                num /= 2;
            }
            
            num = i;
            while (num % 5 == 0) {
                count5s ++;
                num /= 5;
            }
        }
        
        return min(count2s, count5s);
    }
};
