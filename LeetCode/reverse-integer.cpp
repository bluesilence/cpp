#include <limits>;
#include <iostream>;
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (0 == x)
            return 0;
        
        long long absX = (x < 0) ? (0 - x) : x;
        long long rawResult = reverseCore(absX);
        
        if (x < 0) {
            if (rawResult - 1 <= numeric_limits<int>::max())
                return (int)(0 - rawResult);
            else
                return 0;
        }
        else if (x > 0) {
            if (rawResult <= numeric_limits<int>::max())
                return (int)rawResult;
            else
                return 0;
        }
    }
    
private:
    long long reverseCore(long long x) {
        long long result = 0;
        while(x > 0) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        
        return result;
    }
};

void main() {
	Solution test;
	cout<<test.reverse(-123);
}