class Solution {
public:
    bool isPalindrome(int x) {
        long long num = x;
        if (num < 0)
            return false;
            
        if (num < 10)
            return true;
        
        long long tmp = num;
        long long reverse = 0;
        
        while (tmp > 0) {
            reverse = reverse * 10 + tmp % 10;
            tmp /= 10;
        }
        
        return reverse == num;
    }
};
