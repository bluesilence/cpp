class Solution {
public:
    int climbStairs(int n) {
        int *methods = new int[n + 1];
        methods[0] = 1;
        methods[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            methods[i] = methods[i-1] + methods[i-2];
        }
        
        int result = methods[n];
        delete methods;
        
        return result;
    }
};
