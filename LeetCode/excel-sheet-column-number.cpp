class Solution {
public:
    int titleToNumber(string s) {
        long long result = 0;
        const int LEN = s.size();
        
        for (int i = 0; i < LEN; i++) {
            result *= 26;
            result += s[i] - 'A' + 1;
            if (result > INT_MAX)
                return INT_MAX;
        }
        
        return result;
    }
};
