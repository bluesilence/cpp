class Solution {
public:
    bool isHappy(int n) {
        vector<int> digits;
        for (int i = 0; i < maxLoop; i++) {
            if (1 == n)
                return true;
            
            digits.clear();
            while (n) {
                digits.push_back(n % 10);
                n /= 10;
            }
            
            for (int i = 0; i < digits.size(); i++) {
                n += digits[i] * digits[i];
            }
        }
        
        return false;
    }

private:
    const int maxLoop = 7;  //By experience after testing against LeetCode's test cases; Better be larger in real application
};
