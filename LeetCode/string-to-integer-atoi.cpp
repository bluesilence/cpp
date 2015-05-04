class Solution {
public:
    int myAtoi(string str) {
        long long result = 0;
        
        if (str.empty())
            return result;
        
        int i = 0;
        // Remove spaces
        while (i < str.size() && str[i] == ' ')
            i++;
        
        if (i == str.size())
            return result;
        
        // Recognize sign
        bool isNegative = false;
        if (str[i] == '+' || str[i] == '-') {
            if (str[i] == '-')
                isNegative = true;
            
            i++;
        }
        
        // Parse number
        while (i < str.size()) {
            int digit = str[i] - '0';
            if (digit >= 0 && digit <= 9) {
                result *= 10;
                result += digit;
                // Added test case requires boundary conditions must be determined here, because a too large positive long long may result in negative number after negating, and the returning value will be min int instead of max int
                if (!isNegative && result >= numeric_limits<int>::max())
                    return numeric_limits<int>::max();
                else if (isNegative && (0 - result) <= numeric_limits<int>::min())
                    return numeric_limits<int>::min();
            } else {
                break;
            }
            
            i++;
        }
        
        if (isNegative)
            result = 0 - result;
            
        return result;
    }
};
