class Solution {
public:
    int reverse(int x) {
        //If using x, the min negative int may overflow when converted to positive int. So convert x to long long first.
        long long input = x;
        long long result;
        if (input == 0)
            result = 0;
        else if (input > 0)
            result = reverseCore(input);
        else
            result = -1 * reverseCore(0 - input);
        
        if (x > 0 && result > numeric_limits<int>::max() || x < 0 && result < numeric_limits<int>::min())
            return 0;
        else
            return (int)result;
    }

private:
    long long reverseCore(long long input) {
        long long result = 0;
        while (input > 0) {
            result *= 10;
            result += input % 10;
            input /= 10;
        }
        
        return result;
    }
};
