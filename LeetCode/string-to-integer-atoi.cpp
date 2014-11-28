class Solution {
public:
    int atoi(const char *str) {
        while (*str == ' ')
            str++;
            
        int pos = 1;
        if (*str == '+' || *str == '-') {
            if (*str == '-')
                pos = -1;
            str++;
        }
        
        double result = 0;
        while (*str != '\0' && *str >= '0' && *str <= '9') {
            result = result * 10 + *str - '0';
            str++;
        }
        
        result = result * pos;
        if (result > numeric_limits<int>::max())
            return numeric_limits<int>::max();
        else if (result < numeric_limits<int>::min())
            return numeric_limits<int>::min();
        else
            return (int)result;
    }
};
