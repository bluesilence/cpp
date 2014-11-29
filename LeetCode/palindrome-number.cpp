class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else {
            long long target = x;
            long long reverse = 0;
            long long temp = target;
            
            while (temp != 0) {
                reverse = reverse * 10 + temp % 10;
                temp /= 10;
            }
            
            return reverse == target;
        }
    }
};
